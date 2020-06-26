while true
do

make

if [ $? -ne 0 ]
then
	exit 1;
fi

echo
echo '0.41' | ./greedy
#./greedy

echo -n 'Press RETURN to repeat...';
read tmp


done
