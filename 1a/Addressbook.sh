createBook()
{
	echo 
	   if [ -e ffg.txt ]
	then
	    echo "Address Book is already Created..."
	else
	    touch ffg.txt 
	    echo "Address Book Created..."
	fi	    
}

insertBook()
{
	while true
	do
	  echo "Enter your Full Name: "
	  read record
	  
	  if [ "$record" == "q" ]
	  then
	      break
	  fi
	  
	  echo $record >> ffg.txt 
	  echo "Record Inserted Successfully"
	  echo -e "\n"
      break
	 done
	  	  
}

displayBook()
{
    if [ ! -e ffg.txt ]
    then
        echo "Address Book Does not Exit"
    else    
        cat ffg.txt
    fi
}

searchBook()
{
        echo "Enter Data For Search:"
        read data
         if [ -f "ffg.txt" ]
        then 
        result=$(grep -i "$data" "ffg.txt")

        if [ $result ]
        then 
        echo "$result"
        echo "found succesfully"
        else 
        echo "records not found"

        fi 
        
        else 
        echo "records not found"
        fi

}
deleteBook(){
	echo "Delete data from :"
	rm ffg.txt


}
ModifyBook(){
echo "enter the data you want to modify :"
read dt

echo "Enter new string :"
read str



sed -i -e 's/'$dt'/'$str'/' ffg.txt
}

while true
do
	echo
	echo "Welcome To Menu"
	echo "1.Create Address Book"
	echo "2.Insert Data In Book"
    echo "3.Display Data From Book"
    echo "4.Search Data From Book"
    echo "5.Delete Data From Book"
    echo "6.Modify Data from Book" 
	echo "7.Exit"

	echo "Enter Your Choice: "
	read ch

	case $ch in 
		1)createBook;;
		2)insertBook;;
        3)displayBook;;
        4)searchBook;;
        5)deleteBook;;
        6)ModifyBook;;
        7)exit;;
	esac	
done