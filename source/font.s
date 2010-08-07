
@{{BLOCK(font)

@=======================================================================
@
@	font, 128x64@4, 
@	+ palette 256 entries, not compressed
@	+ 128 tiles not compressed
@	Total size: 512 + 4096 = 4608
@
@	Time-stamp: 2009-03-28, 17:49:14
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global fontTiles		@ 4096 unsigned chars
fontTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00133100,0x00133100,0x00133100,0x00133100,0x00144100,0x00022000,0x00255200,0x00022000
	.word 0x00010100,0x00131310,0x00131310,0x00010100,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00010100,0x00131310,0x00131310,0x01333331,0x00131310,0x01333331,0x00131310,0x00131310
	.word 0x00001000,0x00113100,0x01333420,0x00113241,0x00243320,0x01423110,0x00243331,0x00013110
	.word 0x01000220,0x15102552,0x01512552,0x00151220,0x02215100,0x25521510,0x25520151,0x02200010
	.word 0x00061600,0x00623260,0x00636310,0x00636310,0x61623260,0x13232320,0x62321231,0x13233520
	.word 0x00022000,0x00244200,0x00134200,0x00142000,0x00014100,0x00001000,0x00000000,0x00000000

	.word 0x00020000,0x00232000,0x00023200,0x00002310,0x00001310,0x00002310,0x00023200,0x00232000
	.word 0x00002000,0x00023200,0x00232000,0x01320000,0x01310000,0x01320000,0x00232000,0x00023200
	.word 0x00001000,0x00113110,0x01323231,0x00233320,0x01333331,0x00233320,0x01323231,0x00113110
	.word 0x00000000,0x00001000,0x00013100,0x00113110,0x01333331,0x00113110,0x00013100,0x00001000
	.word 0x00000000,0x00000000,0x00011000,0x00122100,0x01233210,0x01233210,0x00142100,0x00014100
	.word 0x00000000,0x00000000,0x00000000,0x00111110,0x01333331,0x00111110,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00011000,0x00122100,0x01255210,0x01255210,0x00122100
	.word 0x52000000,0x55200000,0x25520000,0x02552000,0x00255200,0x00025520,0x00002552,0x00000255

	.word 0x00161600,0x02455420,0x14522746,0x17511571,0x17511571,0x17511571,0x64722741,0x02455420
	.word 0x06610000,0x06542000,0x01574600,0x06571000,0x06576000,0x06556000,0x06556000,0x65555600
	.word 0x00661600,0x02477420,0x14764746,0x14722456,0x02454260,0x06127420,0x65427546,0x65575756
	.word 0x00111600,0x02455420,0x14722746,0x17721256,0x02777160,0x65721256,0x64722546,0x02455420
	.word 0x00110000,0x01746000,0x06574100,0x06555410,0x06752546,0x15751576,0x17775776,0x01576110
	.word 0x01111660,0x65777556,0x01166556,0x02455756,0x64526660,0x65566556,0x64722546,0x02477420
	.word 0x00111600,0x06777420,0x01116746,0x02455756,0x64522776,0x65711576,0x64722546,0x02455420
	.word 0x01111110,0x17777771,0x14711176,0x01441160,0x00144100,0x00015460,0x00015760,0x00015760

	.word 0x00161600,0x02455420,0x64522746,0x64722746,0x02775720,0x64722546,0x64722546,0x02475420
	.word 0x00111100,0x02477420,0x14522741,0x17522741,0x65557420,0x65526610,0x64522541,0x02455420
	.word 0x00011000,0x00122100,0x01233210,0x01233210,0x00122100,0x01233210,0x01233210,0x00122100
	.word 0x00011000,0x00122100,0x01233210,0x01233210,0x00122100,0x01233210,0x01132100,0x00014210
	.word 0x00000000,0x01100000,0x14421000,0x01244210,0x00012331,0x01244210,0x14421000,0x01100000
	.word 0x00000000,0x00111110,0x01333331,0x00111110,0x00111110,0x01333331,0x00111110,0x00000000
	.word 0x00000000,0x00000110,0x00011441,0x01144210,0x13321000,0x01144210,0x00011441,0x00000110
	.word 0x00211200,0x02433420,0x24322342,0x24321331,0x02442110,0x00244100,0x00011000,0x00133100

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00611600,0x02433420,0x64333346,0x65322356,0x63311331,0x13355331,0x13366331,0x13311331
	.word 0x00111110,0x02433331,0x14321331,0x14321331,0x02333331,0x14321331,0x14321331,0x02433331
	.word 0x00111600,0x02455420,0x14322346,0x65561331,0x06661331,0x65561331,0x14322346,0x02455420
	.word 0x00611110,0x02433331,0x64321331,0x13311331,0x13311331,0x13311331,0x64321331,0x02433331
	.word 0x01111110,0x13333331,0x64211331,0x06111331,0x01433331,0x06111331,0x64211331,0x13333331
	.word 0x01111110,0x13333331,0x64211331,0x06111331,0x01433331,0x00111331,0x00001331,0x00001331
	.word 0x00111600,0x01433460,0x14322346,0x65566331,0x01161331,0x13341331,0x13322341,0x13333410

	.word 0x01100110,0x13311331,0x13311331,0x13311331,0x13333331,0x13311331,0x13311331,0x13311331
	.word 0x00111100,0x01433410,0x00233200,0x00133100,0x00133100,0x00133100,0x00233200,0x01433410
	.word 0x01110000,0x13341000,0x13320000,0x13310000,0x13310110,0x13311331,0x14322341,0x02433420
	.word 0x01100110,0x14421331,0x02442331,0x00234331,0x02453331,0x14321331,0x13311331,0x13311331
	.word 0x00000110,0x00001331,0x00001331,0x00001331,0x00001331,0x16001331,0x64211331,0x13333331
	.word 0x11100111,0x13411431,0x13422431,0x13544531,0x13555531,0x13455431,0x13255231,0x15144131
	.word 0x01100110,0x13311431,0x13312331,0x13324331,0x13344331,0x13342331,0x13321331,0x13411331
	.word 0x00111100,0x02433420,0x14322341,0x13311331,0x13311331,0x13311331,0x14322341,0x02433420

	.word 0x00111110,0x02433331,0x14321331,0x13311331,0x14321331,0x02433331,0x00111331,0x00001331
	.word 0x00111100,0x02433420,0x14322341,0x13566531,0x13511531,0x13536531,0x14332541,0x13333420
	.word 0x00111110,0x02433331,0x14321331,0x13311331,0x14321331,0x02333331,0x14321331,0x13411331
	.word 0x00111100,0x02455420,0x14522541,0x01112541,0x02455420,0x14521160,0x14522546,0x02455420
	.word 0x01111110,0x15555551,0x65555556,0x06155160,0x00155100,0x00155100,0x00155100,0x00155100
	.word 0x01100110,0x15511551,0x15511551,0x15511551,0x15511551,0x15522551,0x14555541,0x02455420
	.word 0x01100111,0x15511551,0x15511551,0x15511551,0x15511551,0x64522546,0x01455410,0x00144100
	.word 0x11111111,0x55155155,0x55255255,0x45555554,0x25555552,0x14544541,0x14522541,0x12511521

	.word 0x01100110,0x15511551,0x14511541,0x01455410,0x00144100,0x01455410,0x14511541,0x15511551
	.word 0x01100110,0x15511551,0x15511551,0x14522541,0x01455410,0x00155100,0x00155100,0x00155100
	.word 0x01111110,0x15555551,0x14555556,0x01441160,0x00144100,0x06614410,0x65555541,0x15555551
	.word 0x00111000,0x01334100,0x00113100,0x00013100,0x00013100,0x00013100,0x00113100,0x01334100
	.word 0x01100110,0x14311341,0x01433410,0x13333331,0x01133110,0x13333331,0x01133110,0x00133100
	.word 0x00011100,0x00143310,0x00131100,0x00131000,0x00131000,0x00131000,0x00131100,0x00143310
	.word 0x00001000,0x00013100,0x00141410,0x01410141,0x00100010,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x01111110,0x14333341,0x01111110

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00111100,0x02433310,0x14321100,0x13333420,0x13312341,0x13312341,0x13333420,0x01111100
	.word 0x00000110,0x00001331,0x00111331,0x02433331,0x14321331,0x14321331,0x02433331,0x00111110
	.word 0x00000000,0x00111100,0x01333420,0x00111341,0x00001331,0x00111341,0x01333420,0x00111100
	.word 0x01100000,0x13310000,0x13311100,0x13333420,0x13312341,0x13312341,0x13333420,0x01111100
	.word 0x00000000,0x00111100,0x02433420,0x14312341,0x13333331,0x01111341,0x01333420,0x00111100
	.word 0x00111000,0x02434200,0x14323410,0x06113310,0x06333331,0x00613310,0x00013310,0x00013310
	.word 0x01111100,0x13333420,0x01422341,0x00243331,0x00111331,0x02433331,0x14321341,0x02333410

	.word 0x00000110,0x00001331,0x00111331,0x02433331,0x14321331,0x13311331,0x13311331,0x01100110
	.word 0x00022000,0x00244200,0x00022000,0x00133100,0x00133100,0x00133100,0x00133100,0x00011000
	.word 0x02200000,0x24420000,0x02200000,0x13310000,0x13310210,0x14322441,0x02433420,0x00111100
	.word 0x00001100,0x01113310,0x13413310,0x02323310,0x02333310,0x14323310,0x13413310,0x01101100
	.word 0x00011100,0x00133310,0x00133100,0x00133100,0x00133100,0x00133100,0x00133100,0x00011000
	.word 0x00000000,0x00000000,0x00111110,0x02435331,0x14231331,0x13131331,0x13131331,0x01111110
	.word 0x00000000,0x00000000,0x00111100,0x02433310,0x14323310,0x13313310,0x13313310,0x01111100
	.word 0x00000000,0x00011100,0x00245420,0x01432341,0x01331331,0x01432341,0x00245420,0x00011100

	.word 0x00611660,0x02435556,0x14321356,0x14321331,0x02435331,0x00611331,0x00001331,0x00000110
	.word 0x06611100,0x65553420,0x65312341,0x13312341,0x13353420,0x13311600,0x13310000,0x01100000
	.word 0x00000000,0x00111600,0x02343310,0x13323310,0x01113310,0x00013310,0x00013310,0x00001100
	.word 0x00000000,0x00011100,0x00245420,0x06422346,0x01244261,0x06432246,0x00245420,0x00011100
	.word 0x00000000,0x00001100,0x00113310,0x01333331,0x00113310,0x00123310,0x01333410,0x00111100
	.word 0x00000000,0x01100110,0x13311331,0x13311331,0x13311331,0x13312341,0x13333420,0x01111100
	.word 0x00000000,0x01100110,0x13311331,0x14311341,0x01364310,0x01433410,0x00144100,0x00011000
	.word 0x00000000,0x01100110,0x13311331,0x13311331,0x14333341,0x01311310,0x01411410,0x00100100

	.word 0x00000000,0x01100110,0x14311341,0x01433410,0x00133100,0x01433410,0x14311341,0x01100110
	.word 0x00000000,0x01100110,0x64311341,0x01433360,0x00143100,0x00014310,0x00001431,0x00000110
	.word 0x00000000,0x00111100,0x06355360,0x06436600,0x00644100,0x00615410,0x06335560,0x00111100
	.word 0x00100000,0x01320000,0x00231000,0x00132000,0x00133100,0x00132000,0x00231000,0x01320000
	.word 0x00010000,0x00131000,0x00131000,0x00131000,0x00131000,0x00131000,0x00131000,0x00131000
	.word 0x00000100,0x00002310,0x00013200,0x00023100,0x00133100,0x00023100,0x00013200,0x00002310
	.word 0x02001200,0x13223320,0x02332231,0x00110010,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global fontPal		@ 512 unsigned chars
fontPal:
	.hword 0x0000,0x0001,0x294A,0x7FFF,0x6739,0x7BDE,0x0421,0x7FFF
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(font)
