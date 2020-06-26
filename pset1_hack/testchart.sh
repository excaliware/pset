while true
do

sh makeloop.sh

if [ $? -ne 0 ]
then
	exit 1;
fi

echo
echo '1 0 3 0' | ./chart

echo -n 'Press RETURN to repeat...';
read tmp


done
