# Kconfig Demo for ESP-IDF

This is a training project for learning how to use Kconfig configuration system in ESP-IDF projects. It demonstrates the configuration workflow and best practices for managing project settings.

## Table of Contents
- [About Kconfig](#about-kconfig)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Configuration Files](#configuration-files)
- [Common Commands](#common-commands)
- [Best Practices](#best-practices)

## About Kconfig

Kconfig is a configuration system originally developed for the Linux kernel, adopted by ESP-IDF for managing project and SDK settings. It provides a menu-driven interface for configuring:
- Target chip settings (ESP32, ESP32-S2, ESP32-C3, etc.)
- Component options (Wi-Fi, Bluetooth, FreeRTOS, etc.)
- Project-specific configurations
- Build system parameters

## Prerequisites

Before using this project, ensure you have:
- **ESP-IDF** installed and configured (version 4.0 or later recommended)
- Environment variables set up (run `. $HOME/esp/esp-idf/export.sh` or equivalent)
- Basic familiarity with command line tools

## Getting Started

### 1. Set the Target Device

```bash
idf.py set-target esp32
```

Replace `esp32` with your target chip (esp32, esp32s2, esp32s3, esp32c3, etc.)

### 2. Configure the Project

Launch the interactive configuration menu:

```bash
idf.py menuconfig
```

Navigate through the menu to customize settings for your project.

### 3. Build the Project

```bash
idf.py build
```

### 4. Flash to Device

```bash
idf.py flash
```

### 5. Monitor Output

```bash
idf.py monitor
```

Or combine flash and monitor:

```bash
idf.py flash monitor
```

## Configuration Files

### `sdkconfig`

This file lists all the configuration options for the project. It is auto-generated and ESP-IDF recommends **not manually editing it**.

The file is regenerated/updated any time:
- A command like `idf.py set-target <target>` is run
- `idf.py menuconfig` is used to change configuration
- `idf.py build` is executed (if config changes are detected)

Any time `sdkconfig` is regenerated, the **previous version** is automatically backed up to `sdkconfig.old`.

### `sdkconfig.old`

This file is a backup of the previous version of the `sdkconfig` file. It's useful for comparing changes or reverting configuration mistakes.

### `sdkconfig.defaults`

This file contains the default configuration values for your project. It can be:
- **Manually created**: Define your baseline configuration
- **Auto-generated**: Use `idf.py save-defconfig` to extract custom settings

When you run `idf.py save-defconfig`, ESP-IDF analyzes your `sdkconfig` and saves only the non-default values (like Bluetooth enabled, custom partition table, etc.) to `sdkconfig.defaults`.

**Use cases:**
- Version control: Commit `sdkconfig.defaults` instead of `sdkconfig`
- Team consistency: Ensure all developers start with the same baseline
- CI/CD: Reproducible builds across different environments

## Common Commands

| Command | Description |
|---------|-------------|
| `idf.py menuconfig` | Open interactive configuration menu |
| `idf.py set-target <chip>` | Set target ESP32 chip variant |
| `idf.py save-defconfig` | Save custom config to sdkconfig.defaults |
| `idf.py build` | Build the project |
| `idf.py clean` | Clean build artifacts |
| `idf.py fullclean` | Remove all build files and sdkconfig |
| `idf.py flash` | Flash firmware to device |
| `idf.py monitor` | Open serial monitor |

## Best Practices

1. **Version Control**:
   - Add `sdkconfig.defaults` to version control
   - Add `sdkconfig` and `sdkconfig.old` to `.gitignore`

2. **Configuration Management**:
   - Use `sdkconfig.defaults` for baseline project configuration
   - Document custom configuration choices in this README or comments
   - Use `idf.py save-defconfig` after finalizing configuration changes

3. **Team Collaboration**:
   - Share `sdkconfig.defaults` with team members
   - Document any required manual configuration steps
   - Keep chip-specific settings separate when supporting multiple targets

4. **Testing**:
   - Test with clean builds: `idf.py fullclean && idf.py build`
   - Verify configuration on fresh checkouts
   - Test on actual target hardware, not just in simulation

## Resources

- [ESP-IDF Documentation](https://docs.espressif.com/projects/esp-idf/)
- [Kconfig Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/kconfig.html)
- [ESP-IDF Build System](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html)
