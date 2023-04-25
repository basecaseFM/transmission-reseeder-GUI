#!/bin/bash
IFS_BACKUP=${IFS}
IFS=""

magnetLINK_PATH=$1
HOST=$2
PORT=$3
USERNAME=$4
PASSWORD=$5
echo "test...."

if [[ -z $USERNAME && -z $HOST && -z $PORT ]] ; then
        alias transmission-remote="transmission-remote"
elif [[ -n $USERNAME && -z $HOST && -z $PORT ]] ; then
        alias transmission-remote="transmission-remote --auth $USERNAME:$PASSWORD"
elif [[ -z $USERNAME && -n $HOST && -z $PORT ]] ; then
        alias transmission-remote="transmission-remote $HOST"
elif [[ -z $USERNAME && -z $HOST && -n $PORT ]] ; then
        alias transmission-remote="transmission-remote $PORT"
elif [[ -z $USERNAME && -n $HOST && -n $PORT ]] ; then
        alias transmission-remote="transmission-remote $HOST:$PORT"
elif [[ -n $USERNAME && -n $HOST && -z $PORT ]] ; then
        alias transmission-remote="transmission-remote $HOST --auth $USERNAME:$PASSWORD"
elif [[ -n $USERNAME && -z $HOST && -n $PORT ]] ; then
        alias transmission-remote="transmission-remote $PORT --auth $USERNAME:$PASSWORD"
elif [[ -n $USERNAME && -n $HOST && -n $PORT ]] ; then
        alias transmission-remote="transmission-remote $HOST:$PORT --auth $USERNAME:$PASSWORD"
fi

sh "$magnetLINK_PATH" "$HOST" "$PORT" "$USERNAME" "$PASSWORD"
