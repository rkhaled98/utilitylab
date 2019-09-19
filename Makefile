LABNAME = utilitylab

all: test

test:
	cd vcat && make test
	cd vgrep && make test
	cd vunzip && make test
	cd vzip && make test

clean:
	cd vcat && make clean
	cd vgrep && make clean
	cd vunzip && make clean
	cd vzip && make clean

submit:
	rm -rf $(LABNAME)-submit
	mkdir $(LABNAME)-submit
	cp vcat/vcat.c $(LABNAME)-submit
	cp vgrep/vgrep.c $(LABNAME)-submit
	cp vunzip/vunzip.c $(LABNAME)-submit
	cp vzip/vzip.c $(LABNAME)-submit
	submit334 $(LABNAME)-submit $(LABNAME)-submit
	rm -rf $(LABNAME)-submit
