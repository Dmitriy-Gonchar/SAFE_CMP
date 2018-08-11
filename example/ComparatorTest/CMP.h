//
//  CMP.h
//  ComparatorTest
//
//  Created by Dmitry Gonchar on 11.08.18.
//  Copyright © 2018 test. All rights reserved.
//

#ifndef CMP_h
#define CMP_h

#define STRINGIFY2(X) #X
#define STRINGIFY(X) STRINGIFY2(X)
#define VALUE(x) ([NSValue valueWithBytes: ((__typeof__(x) []){x}) objCType: @encode(__typeof__(x))])

int	println(const char * format, ...);
/**
 *  the universal comparator of the structures or scalar-types
 */
int SAFE_CMP(struct {} obj1, struct {} obj2);

#define println(...) printf("\n" __VA_ARGS__)

#define UNADDRESSABLE(X) ((__typeof__(X) []){X})

#define stringify description.UTF8String

#define isCOMP(A, B) ({BOOL C = __builtin_types_compatible_p(__typeof__(A), __typeof__(B)); println("COMPATIBLE: %s", C? "YES": "NO"); C;})

#ifdef DEBUG

#define SAFE_CMP(A, B) (isCOMP(A, B)\
	? (memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A))\
		? (println("%s(%s) == %s(%s)", STRINGIFY(A), VALUE(A).stringify, STRINGIFY(B), VALUE(B).stringify),\
			memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A)))\
		: (println("%s(%s) == %s(%s)", STRINGIFY(A), VALUE(A).stringify, STRINGIFY(B), VALUE(B).stringify),\
			memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A))))\
	: (perror("\nNON-COMPATIBLE TYPES!"), abort(), 0))

#else

#define SAFE_CMP(A, B) (__builtin_types_compatible_p(__typeof__(A), __typeof__(B))\
	? (memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A))\
		? memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A))\
		: memcmp(UNADDRESSABLE(A), UNADDRESSABLE(B), sizeof(A)))\
	: (perror("\nNON-COMPATIBLE TYPES!"), abort(), 0))

#endif

#endif /* CMP_h */
