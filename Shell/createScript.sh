#!/bin/bash

filename="$1.sh"
echo "#!/bin/bash" > $filename  # $1 primer argument
chmod +x $filename