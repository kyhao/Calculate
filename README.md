# Calculate
Can calculate Basic and some advance calculations.

## ABOUT OBJECT:
Include Two Object:
### 1. `mCalCore` Object<br>
#### include file:<br>
`mCalCore.h` `mCalCore.cpp`<br>
#### operater:<br>
`+` `-` `/` `*` `^` `()` <br>
#### function:<br>
`int calculate(_IN_ const char *buf, _OUT_ double &r);` <br>

### 2. `mCalCorev2` Object<br>
#### include file:<br>
`mCalCore.h` `mCalCore.cpp` `mCalCorev2.h` `mCalCorev2.cpp`<br>
#### operater:<br>
`(-x)` `!()` `sin()` `cos()` `tan()` `ln()` `log()` `sqrt()` `Pi` `e`<br>
#### function:<br>
`int cal(_IN_ const char *buf, _OUT_ double &res);` <br>

### 3. Relationship<br>
`mCalCorev2` is `mCalCore`'s Child<br>
you can use `mCalCorev2` Object to calculate Basic calculations.<br>

## ABOUT ERROR LIST:
	ERROR_1:lose bracket
	ERROR_2:illegal input
	ERROR_3:symbol error
	ERROR_X:UNKNOW ERROR

## SOME PORBLEM
`^` has same priority like `*` `/`
