#ifndef CONFIG_H_
#define CONFIG_H_

#include <string.h>

// Progress bar color
static const unsigned long int PROGRESS_BAR_COLOR = 0xffffff;

// Default download directory (also build directory too)
static const char download_dir[] = "/build_dir"; // Specify "." if you want it to do it in the current directory you are in

// Log_dir when you parse the quiet flag (or shut pms from being verbose)
static const char log_dir[] = "/build_dir/logs";

// Clean sources
static const int clean_sources = 0; // 0 - no cleaning, 1 - clean extracted only, 3 - POWERWASH!

// Force download disabled by default, this will continue downloading even if there is an error, NOT RECOMMENDED TO TOGGLE ON
static const int force_download = 0;

// Omit the quiet flag and permanently shut up pms
static int quiet = 0; // 0 - verbose, 1 - stfu

// Repository support (still needs to be implemented)
#define REPO_SUPPORT 0 // 0 - ONLY BUILDJSON! 1 - gib me repo support!

// Repo Dir, where the repo is stored
static const char repo_dir[] = "/build_dir/repos";

// Repositories (ONLY GIT REPOS)
static const char * const repo_urls[] = {
    "https://github.com/LearnixOS/lxos-repo",
    NULL
};

#endif // CONFIG_H_
