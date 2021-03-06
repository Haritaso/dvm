# Changelog

## [Unreleased]

### Added

- `gc` command to purge unused versions of Deno runtime.
- `set_noprogress` option to curl module to print the download progress.

## [1.1.0](https://github.com/imbsky/dvm/releases/tag/v1.1.0) - 2020-01-04

### Added

- `latest` command to install latest version.

### Fixed

- Fix typos in error messages.

## [1.0.1](https://github.com/imbsky/dvm/releases/tag/v1.0.1) - 2019-11-14

### Changed

- Change all pastel colors to cyan.

## [1.0.0](https://github.com/imbsky/dvm/releases/tag/v1.0.0) - 2019-11-22

### Added

- `DVM_INSTALL_DIR` variable to change the installation directory using the.

### Changed

- Remove some annoying console outputs.

- You can now install without the gunzip.

- Symbolic link is now removed if the version being uninstalled matches the
  version set as the global version.

- Changed the list and list-all commands to ls and ls-remote to avoid module
  name conflicts.

- Use the tags API instead of the release API to speed up the retrieval of a
  list of remote versions.

- Changed primary color of console output from red to cyan.

### Fixed

- Fix an issue causing an error when attempting to install if the installation
  directory does not exist.

- Fix an issue causing an error when trying to use a non-exist version.

## [0.1.0](https://github.com/imbsky/dvm/releases/tag/v0.1.0) - 2019-11-20

Initial version.
