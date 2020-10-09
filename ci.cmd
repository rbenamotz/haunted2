@echo off
pio run -e production
aws s3 cp .pio\build\production\firmware.hex s3://firmwares.benamotz.com/haunted2.hex 
aws s3api put-object-acl --bucket firmwares.benamotz.com --key haunted2.hex --acl public-read