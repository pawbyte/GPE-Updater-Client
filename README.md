# Game Pencil Editor Updater


This is the updator module used to update the GPE project files.

This can be used to update development and release versions.  The update branch can be chosen via the configuration file.  
If no configuration file is present, then the default is to use release versions of everything.

By default, the updater will not make any modifications to files. It will only respond with a return code and/or display a dialog showing update information. To update files, pass in the update flag, detailed in the [Options](#Options) section.

## Options

| Flag | Description                               | 
|------|-------------------------------------------|
| -v   | Version info                              |
| -s   | Silent, No GUI. Just return a return code |
| -u   | Update files in the project               |
| --nb | No Backups                                |