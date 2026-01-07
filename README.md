# Description
This is a training project for getting started with how to use Kconfig in ESP-IDF projects

# Configuration Files
## SDK configuration files
### `sdkconfig`
This file list all the configuration for the project. It is auto-generated and ESP-IDF recommands to not manually edit it.
The file is regenerared/updated any time a command like `idf.py set-target <targer>` is run and when `idf.py menuconfig` is used to change some configuration.
Any time `sdkconfig` is regenerated, the **previous version** is backed up in `sdkconfig.old`.

### `sdkconfig.old`
This file is a backup of the previous version of `sdkconfig` file.

### `sdkconfig.defaults`
This file can be manually created or auto-generated using `idf.py save-defconfig`. ESP-IDF then looks for any custom configuration in `sdkconfig` (like bluethoot enabled) and save it in `sdkconfig.defaults`.
