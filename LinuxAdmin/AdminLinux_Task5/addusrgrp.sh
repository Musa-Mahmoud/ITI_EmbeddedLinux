#!/bin/bash

USERNAME=$1
GROUPNAME=$2

if [ $EUID -ne 0 ]; then
    echo "Permission denied: run the script as sudo or root."
    exit 1
fi

if grep -w "$GROUPNAME:*" /etc/group > /dev/null; then
    echo "Group '$GROUPNAME' already exists."
else
    echo "Group '$GROUPNAME' doesn't exist, creating one..."
    groupadd "$GROUPNAME"
    echo "Group '$GROUPNAME' created successfully"
fi

if grep -w "$USERNAME:*" /etc/passwd > /dev/null; then
    echo "User '$USERNAME' already exists."
else
    echo "User '$USERNAME' doesn't exist, creating one..."
    useradd -m -g "$GROUPNAME" "$USERNAME"
    echo "User '$USERNAME' created successfully"
fi

echo "-Displaying newly added user and group info:"
id "$USERNAME"
getent group "$GROUPNAME"
