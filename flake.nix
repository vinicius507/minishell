{
  inputs = {
    nixpkgs.url = "nixpkgs";
    libft.url = "github:vinicius507/libft";
  };

  outputs = {
    self,
    nixpkgs,
    libft,
  }: let
    allSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];
    forEachSystem = f:
      nixpkgs.lib.genAttrs allSystems (system:
        f {
          pkgs = import nixpkgs {
            inherit system;
            overlays =
              [
                libft.overlays.libft
                libft.overlays.devshell
              ]
              ++ builtins.attrValues self.overlays;
          };
        });
  in {
    checks = forEachSystem ({pkgs}: {
      norminette-check = pkgs.stdenvNoCC.mkDerivation {
        name = "norminette-check";
        src = ./minishell;
        dontBuild = true;
        doCheck = true;
        checkPhase = with pkgs; ''
          ${norminette}/bin/norminette $src
        '';
        installPhase = "touch $out"; # Derivation must build an output.
      };
    });
    packages = forEachSystem ({pkgs}: {
      default = pkgs.minishell;
      minishell = import ./nix/pkgs/minishell.nix {
        inherit (pkgs) lib bear libft readline;
        inherit (pkgs.llvmPackages_12) stdenv;
      };
    });
    overlays = {
      default = self.overlays.minishell;
      minishell = final: _: {
        minishell = self.packages.${final.system}.minishell;
      };
    };
    devShells = forEachSystem ({pkgs}: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          norminette
          valgrind
        ];
      };
    });
  };
}
