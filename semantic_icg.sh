function run() {
	local total_testcases="$1"
	echo "Running: $total_testcases"
	local start=1
	while [ $start -le $total_testcases ]
	do
		printf "\n\n"
		echo Running TestCase $start
		local filename="tests/test"$start".c"
        local filename2="../icg/tests/test"$start".c"
		cd icg
        ./a.out $filename
        cd ..
        cd semantic-analyzer
        ./a.out $filename2
        cd ..
		((start++))
	done
}

number_of_files=`ls -l ./icg/tests/ | egrep -c '^-'`
run $number_of_files
