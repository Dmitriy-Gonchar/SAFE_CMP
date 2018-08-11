//
//  ViewController.m
//  ComparatorTest
//
//  Created by Dmitry Gonchar on 11.08.18.
//  Copyright © 2018 test. All rights reserved.
//

#import "ViewController.h"
#import "CMP.h"

@implementation ViewController

typedef struct
{
	int x, y, z;
} Coord3i;

- (void)viewDidLoad
{
	[super viewDidLoad];
///	SAFE_CMP instead of thousand CGPointEqualToPoint, CGRectEqualToRect, e.t.c.

/// CGPoint compare:
	CGPoint myPoint = {0, 1},
			myOtherPoint = {0, 1};
	BOOL isEqual = !SAFE_CMP(myPoint, myOtherPoint);

/// CGRect compare:
	NSRect myRect = {0, 0, 1, 1};
	NSRect myOtherRect = {1, 1, 0, 0};
	isEqual = !SAFE_CMP(myRect, myOtherRect);

/// composite-named CGRect-struct compare:
	isEqual = !SAFE_CMP(self.view.frame, self.view.window.frame);

/// custom-type Coord3i-struct compare:
	Coord3i coord1 = {1, 2, 3},
			coord2 = {1, 2, 3};
	isEqual = !SAFE_CMP(coord1, coord2);

/// non-compatible types compare:
	isEqual = !SAFE_CMP(coord1, myPoint); // <-- abort
}

@end
