run:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -e --timeout 10
all:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases --timeout 10
verbose:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -e -v --timeout 10
all-verbose:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -v --timeout 10
validate:
	python3 submission_validator.py