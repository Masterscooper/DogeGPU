 #!/usr/bin/env bash

 # Execute this file to install the dogpu cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Dogpu-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Dogpu-Qt.app/Contents/MacOS/dogpud /usr/local/bin/dogpud
 sudo ln -s ${LOCATION}/Dogpu-Qt.app/Contents/MacOS/dogpu-cli /usr/local/bin/dogpu-cli
