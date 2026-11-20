@ Wally's private General MIDI drum mapping (notes 36-57).
@ Keep this after programmable_wave_data.inc: the base game's
@ programmable wave samples must retain their 4-byte alignment.
	.align 2
@ Key splits for the Wally battle drum kit (GM keys 36 to 57).
.set KeySplitTableWallyDrums, . - 36
	.byte 0  @ 36
	.byte 1  @ 37
	.byte 1  @ 38
	.byte 2  @ 39
	.byte 2  @ 40
	.byte 2  @ 41
	.byte 2  @ 42
	.byte 2  @ 43
	.byte 2  @ 44
	.byte 2  @ 45
	.byte 3  @ 46
	.byte 2  @ 47
	.byte 2  @ 48
	.byte 2  @ 49
	.byte 2  @ 50
	.byte 2  @ 51
	.byte 4  @ 52
	.byte 2  @ 53
	.byte 2  @ 54
	.byte 5  @ 55
	.byte 2  @ 56
	.byte 4  @ 57
	.align 2
