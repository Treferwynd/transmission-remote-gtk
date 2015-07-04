# Introduction #

The local command feature was introduced in 0.7, allowing you to call another application or script with details of one or more torrents. For example, to open a remote folder or download it to your local host.

# Details #

Local commands can be configured through the local settings dialog. They are associated with the current profile. Set a label, and a command with variables.

Commands can be invoked by right clicking on a torrent/torrents, where you will see the commands in the menu or in a commands submenu if you have defined a few.

# Variables #

The syntax for variables is %{variablename}.

A variable name is either
  * **a) a member in the torrent response object from the server.**
  * See: [The Transmission RPC spec](https://trac.transmissionbt.com/browser/trunk/extras/rpc-spec.txt) in the 'torrent-get' section.
  * Examples: %{full-path} %{name} %{path} %{hash} %{id} %{downloadDir}


  * **b) profile configuration.**
  * See: a profile object in the config file. This is typically ~/.config/transmission-remote-gtk/config.json on UNIX, and C:\Users\USER\Local Settings\Application Data\transmission-remote-gtk on Windows.
  * Examples: %{hostname} %{profile-name}

  * **c) something in the latest session-get response (remote settings).**
  * See [The Transmission RPC spec](https://trac.transmissionbt.com/browser/trunk/extras/rpc-spec.txt) in the 'session-get' section.
  * Examples: %{download-dir}

# Repeaters #

If you would like to execute with multiple torrents in the arguments, set a repeater field in square brackets after the variable. For example:

  * konsole -e ssh -t server.domain bash -i ~/bin/tmr-ssh.sh %{id}[ ]

# Pull script #

[An example script which uses this feature to download one or more torrents using rsync.](http://code.google.com/p/transmission-remote-gtk/source/browse/extra/tpull.sh)

# Examples #

  * dolphin 'sftp://${hostname}%{full-path}'
  * konsole -e ssh -t server.domain bash -i ~/bin/tmr-ssh.sh %{id}
  * konsole -e ssh -t server.domain bash -i ~/bin/tmr-ssh.sh %{id}[ ]
  * transmission-remote %{hostname}:%{port} -n %{username}:%{password} -t %{id} --move /home/ajf88/test
  * sh -c "transmission-remote %{hostname} -t %{id} -i | grep -ioE '(https?://|www\.).