### GPIO Setup
#### On the host push all the bash files to the root of GalileoGen2
```
$ source push.sh:
```
#### On the Galileo Gen2 ($root)
```
$ groupadd -r examgroup
$ groupmems -g examgroup -a <USERNAME>
$ cp ~/<NEEDED_INIT_BASH> /etc/init.d
$ chmod +x /etc/init.d/<NEEDED_INIT_BASH>
$ update-rc.d <NEEDED_INIT_BASH> defaults
$ reboot
```

#### To remove defaults
```
$ update-rc.d -f <INIT_BASH_TO_REMOVE> remove
```
