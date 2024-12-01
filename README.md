# Pack My Sh*t
## What is PMS?
PMS is essentially a minimal package manager. Okay, not really, for now, it just runs basic build scripts in the form of a .json.
## Why make this?
Hi I'm cowmonk, the founder and maintainer of this beauty, being a gigachad LFS user, I felt it was time to start making my own package manager, and with the firey passion to do something in C, pms came into fruition.
### Where the name originates
I have to give credit because the name pms originally came from Learnix's discord server from a **very** active member of the community, if you want to know him, you will have to 👊 SMASH 👊 THAT SUBSCRIBE BUTTON and join LearnixTV's discord server 😜.
As also the creator of LearnixOS, although it's kinda in a perpetual shadow prison because I haven't really gotten any time because of work and among other things, pms was originally made as an idea for LearnixOS, in which was supposed to be LFS based. Of course, seeing how pms is now in my repository, LearnixOS has moved from being LFS based, to Gentoo based, to finally being decided as being Void based.
### What will happen to pms?
I hear you wonder. Well, after realizing that creating a distribution from scratch (and making it accessible and easy to use for the normal user) was absolutely mind boggling, pms naturally fell into obscurity...
UNTIL TODAY! After the first mention of pms, it naturally stayed as a little rat worm that couldn't get out of my head. After my switch to LFS full time as my daily driver, I realized that I could make an excuse of turning pms into a real thing. This will be much more actively developed than LearnixOS (hopefully), and help me increase my knowledge and understanding of C and the Linux system.
### UPDATE
LearnixOS is moving to LFS based again! PMS is now the official package manager for LearnixOS. We as the LearnixOS dev team will be maintaining and creating awesome utilities that are around that Learnix ecosystem!
## Planned features
- Json package builds
  - No longer that we must SUFFER with the terrible looks and garbage looking ebuilds and PKGBUILDS from arch, and the difficulty of understanding what it really does (I'm looking at you gentoo, it's okay but I really don't like the fact you can't see what enabling USE flags will do in ebuilds). I am also hopping it makes the barrier to entry a lot easier, creating an "AUR" or "Gentoo Overlays" of some sort. Of course, for now, creating these json pkg build files are all manual, which can get annoying, which a automation of creating pkg build files will be created one day.
- Minimal to the bone!
  - For now, I am trying to get the base stuff down, creating a package manager is not easy but I will try my best to follow suckless philosophy and make it easy to hack. Additionally I do want to minimize the dependencies and make sure it's as lightweight as I can, obviously, my choice in using json as the pkg build was obviously a cosmetic choice. Comments are seen throughout the project and they can help some people understand the mess of a job I am doing.
- So easy to use, even a baby can use it!
  - As this is more of a build script package manager, it will be sourced based, however using gentoo's portage manager as a guide, I want to make pms have less sloc and minimal whilst the tools and utility of the package will be as similar or even better than portage, such as syncing and updating packages, (and maybe even USE flags). This will come with time, as I will have to figure out how to implement a USE flag system to pms.
- And much more to come!
# Building
### Prerequisites:
- C compiler (such as clang, gcc, or tcc)
- C libraries
- make
- curl
- cjson[^1]

#### Optional dependencies
- git (repo support and development versions of packages, which is coming soon)

### Actually building it
You will either download the tar from the releases, or get the development pms through git.
Either way, the process will be basically the same. Here's the process (for the beta version):
```
git clone https://github.com/Rekketstone/pms.git pms
cd pms
make
```
For the beta version, there is no installing it yet, however you can move the created binary to /usr/bin and run pms normally. There will be a config.mk and you can edit it to your desires, there is currently a plan to set prefixes and other stuff.
# Usage
### The pkg.json file
The naming scheme can be anything you desire, but to be frank, the hope is that the naming will be like this in pratice: {package_name}-{ver}.json
Here is an example json package file for your viewing desires
###### mypackage-1.0.0.json
```
{
  "pkgname": "mypackage",
  "version": "1.0.0",
  "source": ["http://example.com/mypackage-1.0.0.tar.gz"],
  "patches": ["http://example.com/nofstack.patch"], // This can be omitted from the file no problem, this is just optional stuff
  "build": [
    "tar -xzf mypackage-1.0.0.tar.gz", // This is planned to be not needed, we will automatically unzip/untar the package for you
    "cd mypackage-1.0.0", // This is also planned to not be needed, so that we can automatically patch for you if there are patches available
    "./configure",
    "make",
    "make install"  // Placeholder - actual installation would need to be defined.
  ],
   "depends": ["libxyz", "libpng", "libass"]
}
```
### Running pms
For now pms is very bare, with only four arguments that you can parse to it. You can only run build scripts for now following the mypackage.json example.
```
$ pms --version
pms - Pack My Sh*t version: 0.0.1-beta
$ pms --help
Usage: pms [options] <pkgbuild.json>
Options:
    -h, --help      Display this help message
    -v, --version   Display version information
$ pms --quiet neofetch.json
Fetching sources... Skipping download: 7.1.0.tar.gz already downloaded!
 Done!
Fetching patches...  Done!
neofetch-7.1.0/
neofetch-7.1.0/.github/
neofetch-7.1.0/.github/ISSUE_TEMPLATE.md
neofetch-7.1.0/.github/PULL_REQUEST_TEMPLATE.md
neofetch-7.1.0/.travis.yml
neofetch-7.1.0/CONTRIBUTING.md
neofetch-7.1.0/LICENSE.md
neofetch-7.1.0/Makefile
neofetch-7.1.0/README.md
neofetch-7.1.0/neofetch
neofetch-7.1.0/neofetch.1
```
Report any bugs and help make this project become an actual usable source based package manager!
# Credits
It's because of these projects that pms can actually function, so thanks :-)
- [CJSON](https://github.com/DaveGamble/cJSON)
  - "Ultralightweight JSON parser in ANSI C"
[^1]: https://github.com/DaveGamble/cJSON
