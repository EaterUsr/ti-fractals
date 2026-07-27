{
  inputs = {
    toolchain = {
      url = "git+https://codeberg.org/clevor/ce-programs";
      inputs.flake-utils.follows = "flake-utils";
    };
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      toolchain,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachSystem [ "x86_64-linux" "x86_64-darwin" ] (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
	ce-pkgs = toolchain.legacyPackages.${system};
      in
      {
        packages.default = toolchain.legacyPackages.${system}.buildCEProgram {
          name = "ti-fractals";
          src = self;
        };

	devShells.default = pkgs.mkShell {
	  packages = (with ce-pkgs; [
	    cemu-ti
	    ce-toolchain
	    tilp2
	  ]) ++ (with pkgs; [ clang-tools ]);
	};
      }
    );
}

