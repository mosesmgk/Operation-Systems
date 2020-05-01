# Name: Moses Garcia
# Date: March 10, 2020
# Title: Lab1 Computing Area of Circle
# Description: This program computes area of a circle
#!/bin/bash
echo Executing $0
echo $(/bin/ls | wc -l) files wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "salagtash" ]
then
echo "now you can proceed"
else
echo "Check who logged in"
fi
response="Yes"
while [ $response != "No" ]
do
echo "Enter the radius of a circle: "
read RADUIS
PI=3.14159
AREA=$(echo "$PI*($RADUIS^2)"|bc)
echo "Area of a circle is $AREA"
echo "Would you like to repeat for another Circle  [Yes/No]?"
read response
done
      