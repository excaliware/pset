while true
do

make

if [ $? -ne 0 ]
then
	exit 1;
fi

echo
echo '1 2 3 4' | ./chart

echo -n 'Press RETURN to repeat...';
read tmp


done
