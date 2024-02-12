#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
  // exit if nothing given
  if (argc == 0) {
    return 0;
  }

/**************************
*         GAMES
**************************/
  // Path of Exile
  if (strcmp(argv[1], "poe") == 0) {
    ShellExecute(
      NULL,
      "open",
      "C:\\Program Files (x86)\\Path of Exile\\Client.exe",
      NULL,
      "C:\\Program Files (x86)\\Path of Exile",
      0);
  }
  // Path of Building
  else if (strcmp(argv[1], "pob") == 0) {
    ShellExecute(
      NULL,
      "open",
      "C:\\Users\\Calvin\\Main\\Games\\Path of Building (LocalIdentity)\\Path of Building.exe",
      NULL,
      "C:\\Users\\Calvin\\Main\\Games\\Path of Building (LocalIdentity)",
      0);
  }
  // Nox
  else if (strcmp(argv[1], "nox") == 0) {
    ShellExecute(
      NULL,
      "open",
      "G:\\Games\\Nox\\bin\\Nox.exe",
      NULL,
      "G:\\Games\\Nox",
      0);
  }

/**************************
*         ETC.
**************************/
  // Visual Studio Code
  else if (strcmp(argv[1], "code") == 0) {
    ShellExecute(
      NULL,
      "open",
      "G:\\Microsoft VS Code\\Code.exe",
      NULL,
      "G:\\Microsoft VS Code",
      0);
  }

  return 0;
}