while true
do

sh makeloop.sh

if [ $? -ne 0 ]
then
	exit 1;
fi

echo
echo '378282246310005' | ./credit
#./credit

echo -n 'Press RETURN to repeat...';
read tmp


done
