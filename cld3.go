//go:generate protoc --cpp_out=./ feature_extractor.proto sentence.proto task_spec.proto

// Package cld3 implements language detection using the Compact Language Detector v3.
//
// This packages includes the relevant sources from the CLD3 project, so it doesn't require any external dependencies. For more information on CLD3, see https://github.com/google/cld3/ .
package gocld33

// #cgo CXXFLAGS: -std=c++11 -Wno-undefined-var-template
// #cgo pkg-config: protobuf
// #include <stdlib.h>
// #include "cld3.h"
import "C"
import (
	"unsafe"
)

func Detect(text string) string {
	cs := C.CString(text)
	defer C.free(unsafe.Pointer(cs))
	res:=C.lang_detect(cs)
	return C.GoStringN(res.language, res.len_language)
}