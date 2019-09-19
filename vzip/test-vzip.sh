#! /bin/bash

if ! [[ -x vzip ]]; then
    echo "vzip executable does not exist"
    exit 1
fi

../run-tests.sh $*


