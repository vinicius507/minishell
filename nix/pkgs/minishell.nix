{
  lib,
  bear,
  libft,
  stdenv,
  readline,
}:
stdenv.mkDerivation {
  pname = "minishell";
  version = "1.0.0";
  src = ../../minishell;
  nativeBuildInputs = [
    readline
  ];
  buildPhase = ''
    export LIBFT_DIR=${libft}
    ${bear}/bin/bear -- make
  '';
  installPhase = ''
    mkdir -p $out/bin
    cp minishell $out/bin/minishell
    cp compile_commands.json $out/compile_commands.json
  '';
  meta = with lib; {
    description = "A simple shell";
    license = licenses.agpl3Only;
    mainProgram = "minishell";
  };
}
