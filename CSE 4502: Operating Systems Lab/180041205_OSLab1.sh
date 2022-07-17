#Task 1
mkdir parent
cd parent
mkdir -p sub1/sub2/sub3/child
cd sub1/sub2/sub3/child
touch exampleTextFile.txt

#Task 2
cd /
echo "Destination Path: "
read destAddressVar
cd #1
cd parent/sub1/sub2/sub3/child
cp exampleTextFile.txt test.txt #Here, exampleTextFile.txt is test1.txt, just differently named.
cd #2
touch $destAddressVar/test2.txt
cd /
cd #3
cp parent/sub1/sub2/sub3/child/test.txt $destAddressVar/test2.txt

cd
chmod +wx $destAddressVar/test2.txt
chmod +wx parent/sub1/sub2/sub3/child/exampleTextFile.txt
chmod +wx parent/sub1/sub2/sub3/child/test.txt