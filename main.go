package main

// #cgo LDFLAGS: -lpcre
// #include "regex_match.h"
import "C"
import "fmt"

func main() {
	pattern := "a.b"
	inputString := "acb"

	result := C.match_pcre2(C.CString(pattern), C.CString(inputString))
	if result > 0 {
		fmt.Println("Match found!")
	} else if result == -1 {
		fmt.Println("Error occurred.")
	} else {
		fmt.Println("No match found.")
	}
}
