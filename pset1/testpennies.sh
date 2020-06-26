while true
do

make

if [ $? -ne 0 ]
then
	exit 1;
fi

echo
echo '31 1' | ./pennies

echo -n 'Press RETURN to repeat...';
read tmp


done
