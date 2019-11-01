{ pkgs ? import <nixpkgs> {} }:
with pkgs;
mkShell {
  # this will make all the build inputs from hello and gnutar
  # available to the shell environment
  # inputsFrom = with pkgs; [ hello gnutar ];
  buildInputs = [ boost ];
}
