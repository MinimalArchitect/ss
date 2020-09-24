CC = cc

CFLAGS = -Wall -g -std=c99 -pedantic
DEPS = -lm

.PHONY: all clean
all: train_languagemodel speechrecognition

OBJECTS = vector.o matrix.o ctc_decoder.o classifier.o
TRAIN_OBJECTS = vector.o matrix.o classifier.o ctc_decoder.o train_languagemodel.o

.SUFFIXES = .c .o

speechrecognition: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(DEPS) $(OBJECTS)

train_languagemodel: $(TRAIN_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(DEPS) $(TRAIN_OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $<

vector.o: vector.c vector.h
matrix.o: matrix.c matrix.h vector.h
ctc_decoder.o: ctc_decoder.c ctc_decoder.h vector.h
test.o: test.c ctc_decoder.h matrix.h vector.h

clean:
	rm -rf *.o speechrecognition train_languagemodel

TESTS = test_vector test_matrix test_classifier test_ctc_decoder

test: $(TESTS)
	time ./test_vector
	time ./test_matrix
	time ./test_classifier
	time ./test_ctc_decoder
	@rm -rf *.o $(TESTS)
	@echo "Testing successful!"

test_vector: test_vector.o vector.o
	$(CC) $(LDFLAGS) -o $@ $(DEPS) test_vector.o vector.o

test_matrix: test_matrix.o matrix.o
	$(CC) $(LDFLAGS) -o $@ $(DEPS) test_matrix.o matrix.o vector.o

test_classifier: test_classifier.o classifier.o matrix.o vector.o
	$(CC) $(LDFLAGS) -o $@ $(DEPS) test_classifier.o classifier.o matrix.o vector.o

test_ctc_decoder: test_ctc_decoder.o ctc_decoder.o vector.o
	$(CC) $(LDFLAGS) -o $@ $(DEPS) test_ctc_decoder.o ctc_decoder.o vector.o
