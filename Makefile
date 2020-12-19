all:
	esy x App

deps:
	esy --opam-repository-local /home/manas/development/prometheansacrifice/multicore-opam --opam-override-repository-remote https://github.com/ManasJayanth/multicore-esy-opam-overrides 
