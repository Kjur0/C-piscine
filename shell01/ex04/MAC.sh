#!/bin/sh

ifconfig -a | grep -i "ether " | awk '{print $2}'
