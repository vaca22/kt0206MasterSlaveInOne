#include "wav_linker.h"

#if(WAV_EN)

.section .FLASH_WAV_SECTION0, "ax"
	.align 2, 0

/*--------------------------------WAV_0--------------------------------*/
#ifdef WAV_0
	.equiv WAV_size0, (WAV_end0 - WAV_start0)
	.global WAV_start0
	.global WAV_size0
WAV_start0:
	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_0)
	.align 2, 0
WAV_end0:
#endif
/*----------------------------------------------------------------------*/


/*--------------------------------WAV_1---------------------------------*/
#ifdef WAV_1
	.equiv WAV_size1, (WAV_end1 - WAV_start1)
	.global WAV_start1
	.global WAV_size1
WAV_start1:
	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_1)
	.align 2, 0
WAV_end1:
#endif
/*----------------------------------------------------------------------*/


/*--------------------------------WAV_2---------------------------------*/
#ifdef WAV_2
	.equiv WAV_size2, (WAV_end2 - WAV_start2)
	.global WAV_start2
	.global WAV_size2
WAV_start2:
	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_2)
	.align 2, 0
WAV_end2:
#endif
/*----------------------------------------------------------------------*/


/*--------------------------------WAV_3---------------------------------*/
#ifdef WAV_3
	.equiv WAV_size3, (WAV_end3 - WAV_start3)
	.global WAV_start3
	.global WAV_size3
WAV_start3:
	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_3)
	.align 2, 0
WAV_end3:
#endif
/*----------------------------------------------------------------------*/

/*--------------------------------WAV_4---------------------------------*/
#ifdef WAV_4
	.equiv WAV_size4, (WAV_end4 - WAV_start4)
	.global WAV_start4
	.global WAV_size4
WAV_start4:
	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_4)
	.align 2, 0
WAV_end4:
#endif
/*----------------------------------------------------------------------*/

///*--------------------------------WAV_5---------------------------------*/
//#ifdef WAV_5
//	.equiv WAV_size5, (WAV_end5 - WAV_start5)
//	.global WAV_start5
//	.global WAV_size5
//WAV_start5:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_5)
//	.align 2, 0
//WAV_end5:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_6---------------------------------*/
//#ifdef WAV_6
//	.equiv WAV_size6, (WAV_end6 - WAV_start6)
//	.global WAV_start6
//	.global WAV_size6
//WAV_start6:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_6)
//	.align 2, 0
//WAV_end6:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_7---------------------------------*/
//#ifdef WAV_7
//	.equiv WAV_size7, (WAV_end7 - WAV_start7)
//	.global WAV_start7
//	.global WAV_size7
//WAV_start7:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_7)
//	.align 2, 0
//WAV_end7:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_8---------------------------------*/
//#ifdef WAV_8
//	.equiv WAV_size8, (WAV_end8 - WAV_start8)
//	.global WAV_start8
//	.global WAV_size8
//WAV_start8:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_8)
//	.align 2, 0
//WAV_end8:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_9---------------------------------*/
//#ifdef WAV_9
//	.equiv WAV_size9, (WAV_end9 - WAV_start9)
//	.global WAV_start9
//	.global WAV_size9
//WAV_start9:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_9)
//	.align 2, 0
//WAV_end9:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_10--------------------------------*/
//#ifdef WAV_10
//	.equiv WAV_size10, (WAV_end10 - WAV_start10)
//	.global WAV_start10
//	.global WAV_size10
//WAV_start10:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_10)
//	.align 2, 0
//WAV_end10:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_11--------------------------------*/
//#ifdef WAV_11
//	.equiv WAV_size11, (WAV_end11 - WAV_start11)
//	.global WAV_start11
//	.global WAV_size11
//WAV_start11:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_11)
//	.align 2, 0
//WAV_end11:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_12--------------------------------*/
//#ifdef WAV_12
//	.equiv WAV_size12, (WAV_end12 - WAV_start12)
//	.global WAV_start12
//	.global WAV_size12
//WAV_start12:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_12)
//	.align 2, 0
//WAV_end12:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_13--------------------------------*/
//#ifdef WAV_13
//	.equiv WAV_size13, (WAV_end13 - WAV_start13)
//	.global WAV_start13
//	.global WAV_size13
//WAV_start13:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_13)
//	.align 2, 0
//WAV_end13:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_14--------------------------------*/
//#ifdef WAV_14
//	.equiv WAV_size14, (WAV_end14 - WAV_start14)
//	.global WAV_start14
//	.global WAV_size14
//WAV_start14:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_14)
//	.align 2, 0
//WAV_end14:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_15--------------------------------*/
//#ifdef WAV_15
//	.equiv WAV_size15, (WAV_end15 - WAV_start15)
//	.global WAV_start15
//	.global WAV_size15
//WAV_start15:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_15)
//	.align 2, 0
//WAV_end15:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_16--------------------------------*/
//#ifdef WAV_16
//	.equiv WAV_size16, (WAV_end16 - WAV_start16)
//	.global WAV_start16
//	.global WAV_size16
//WAV_start16:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_16)
//	.align 2, 0
//WAV_end16:
//#endif
///*----------------------------------------------------------------------*/
//
//
///*--------------------------------WAV_17--------------------------------*/
//#ifdef WAV_17
//	.equiv WAV_size17, (WAV_end17 - WAV_start17)
//	.global WAV_start17
//	.global WAV_size17
//WAV_start17:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_17)
//	.align 2, 0
//WAV_end17:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_18--------------------------------*/
//#ifdef WAV_18
//	.equiv WAV_size18, (WAV_end18 - WAV_start18)
//	.global WAV_start18
//	.global WAV_size18
//WAV_start18:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_18)
//	.align 2, 0
//WAV_end18:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_19--------------------------------*/
//#ifdef WAV_19
//	.equiv WAV_size19, (WAV_end19 - WAV_start19)
//	.global WAV_start19
//	.global WAV_size19
//WAV_start19:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_19)
//	.align 2, 0
//WAV_end19:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_20--------------------------------*/
//#ifdef WAV_20
//	.equiv WAV_size20, (WAV_end20 - WAV_start20)
//	.global WAV_start20
//	.global WAV_size20
//WAV_start20:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_20)
//	.align 2, 0
//WAV_end20:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_21--------------------------------*/
//#ifdef WAV_21
//	.equiv WAV_size21, (WAV_end21 - WAV_start21)
//	.global WAV_start21
//	.global WAV_size21
//WAV_start21:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_21)
//	.align 2, 0
//WAV_end21:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_22--------------------------------*/
//#ifdef WAV_22
//	.equiv WAV_size22, (WAV_end22 - WAV_start22)
//	.global WAV_start22
//	.global WAV_size22
//WAV_start22:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_22)
//	.align 2, 0
//WAV_end22:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_23--------------------------------*/
//#ifdef WAV_23
//	.equiv WAV_size23, (WAV_end23 - WAV_start23)
//	.global WAV_start23
//	.global WAV_size23
//WAV_start23:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_23)
//	.align 2, 0
//WAV_end23:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_24--------------------------------*/
//#ifdef WAV_24
//	.equiv WAV_size24, (WAV_end24 - WAV_start24)
//	.global WAV_start24
//	.global WAV_size24
//WAV_start24:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_24)
//	.align 2, 0
//WAV_end24:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_25--------------------------------*/
//#ifdef WAV_25
//	.equiv WAV_size25, (WAV_end25 - WAV_start25)
//	.global WAV_start25
//	.global WAV_size25
//WAV_start25:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_25)
//	.align 2, 0
//WAV_end25:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_26--------------------------------*/
//#ifdef WAV_26
//	.equiv WAV_size26, (WAV_end26 - WAV_start26)
//	.global WAV_start26
//	.global WAV_size26
//WAV_start26:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_26)
//	.align 2, 0
//WAV_end26:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_27--------------------------------*/
//#ifdef WAV_27
//	.equiv WAV_size27, (WAV_end27 - WAV_start27)
//	.global WAV_start27
//	.global WAV_size27
//WAV_start27:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_27)
//	.align 2, 0
//WAV_end27:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_28--------------------------------*/
//#ifdef WAV_28
//	.equiv WAV_size28, (WAV_end28 - WAV_start28)
//	.global WAV_start28
//	.global WAV_size28
//WAV_start28:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_28)
//	.align 2, 0
//WAV_end28:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_29--------------------------------*/
//#ifdef WAV_29
//	.equiv WAV_size29, (WAV_end29 - WAV_start29)
//	.global WAV_start29
//	.global WAV_size29
//WAV_start29:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_29)
//	.align 2, 0
//WAV_end29:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_30--------------------------------*/
//#ifdef WAV_30
//	.equiv WAV_size30, (WAV_end30 - WAV_start30)
//	.global WAV_start30
//	.global WAV_size30
//WAV_start30:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_30)
//	.align 2, 0
//WAV_end30:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_31--------------------------------*/
//#ifdef WAV_31
//	.equiv WAV_size31, (WAV_end31 - WAV_start31)
//	.global WAV_start31
//	.global WAV_size31
//WAV_start31:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_31)
//	.align 2, 0
//WAV_end31:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_32--------------------------------*/
//#ifdef WAV_32
//	.equiv WAV_size32, (WAV_end32 - WAV_start32)
//	.global WAV_start32
//	.global WAV_size32
//WAV_start32:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_32)
//	.align 2, 0
//WAV_end32:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_33--------------------------------*/
//#ifdef WAV_33
//	.equiv WAV_size33, (WAV_end33 - WAV_start33)
//	.global WAV_start33
//	.global WAV_size33
//WAV_start33:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_33)
//	.align 2, 0
//WAV_end33:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_34--------------------------------*/
//#ifdef WAV_34
//	.equiv WAV_size34, (WAV_end34 - WAV_start34)
//	.global WAV_start34
//	.global WAV_size34
//WAV_start34:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_34)
//	.align 2, 0
//WAV_end34:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_35--------------------------------*/
//#ifdef WAV_35
//	.equiv WAV_size35, (WAV_end35 - WAV_start35)
//	.global WAV_start35
//	.global WAV_size35
//WAV_start35:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_35)
//	.align 2, 0
//WAV_end35:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_36--------------------------------*/
//#ifdef WAV_36
//	.equiv WAV_size36, (WAV_end36 - WAV_start36)
//	.global WAV_start36
//	.global WAV_size36
//WAV_start36:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_36)
//	.align 2, 0
//WAV_end36:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_37--------------------------------*/
//#ifdef WAV_37
//	.equiv WAV_size37, (WAV_end37 - WAV_start37)
//	.global WAV_start37
//	.global WAV_size37
//WAV_start37:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_37)
//	.align 2, 0
//WAV_end37:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_38--------------------------------*/
//#ifdef WAV_38
//	.equiv WAV_size38, (WAV_end38 - WAV_start38)
//	.global WAV_start38
//	.global WAV_size38
//WAV_start38:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_38)
//	.align 2, 0
//WAV_end38:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_39--------------------------------*/
//#ifdef WAV_39
//	.equiv WAV_size39, (WAV_end39 - WAV_start39)
//	.global WAV_start39
//	.global WAV_size39
//WAV_start39:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_39)
//	.align 2, 0
//WAV_end39:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_40--------------------------------*/
//#ifdef WAV_40
//	.equiv WAV_size40, (WAV_end40 - WAV_start40)
//	.global WAV_start40
//	.global WAV_size40
//WAV_start40:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_40)
//	.align 2, 0
//WAV_end40:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_41--------------------------------*/
//#ifdef WAV_41
//	.equiv WAV_size41, (WAV_end41 - WAV_start41)
//	.global WAV_start41
//	.global WAV_size41
//WAV_start41:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_41)
//	.align 2, 0
//WAV_end41:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_42--------------------------------*/
//#ifdef WAV_42
//	.equiv WAV_size42, (WAV_end42 - WAV_start42)
//	.global WAV_start42
//	.global WAV_size42
//WAV_start42:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_42)
//	.align 2, 0
//WAV_end42:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_43--------------------------------*/
//#ifdef WAV_43
//	.equiv WAV_size43, (WAV_end43 - WAV_start43)
//	.global WAV_start43
//	.global WAV_size43
//WAV_start43:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_43)
//	.align 2, 0
//WAV_end43:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_44--------------------------------*/
//#ifdef WAV_44
//	.equiv WAV_size44, (WAV_end44 - WAV_start44)
//	.global WAV_start44
//	.global WAV_size44
//WAV_start44:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_44)
//	.align 2, 0
//WAV_end44:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_45--------------------------------*/
//#ifdef WAV_45
//	.equiv WAV_size45, (WAV_end45 - WAV_start45)
//	.global WAV_start45
//	.global WAV_size45
//WAV_start45:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_45)
//	.align 2, 0
//WAV_end45:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_46--------------------------------*/
//#ifdef WAV_46
//	.equiv WAV_size46, (WAV_end46 - WAV_start46)
//	.global WAV_start46
//	.global WAV_size46
//WAV_start46:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_46)
//	.align 2, 0
//WAV_end46:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_47--------------------------------*/
//#ifdef WAV_47
//	.equiv WAV_size47, (WAV_end47 - WAV_start47)
//	.global WAV_start47
//	.global WAV_size47
//WAV_start47:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_47)
//	.align 2, 0
//WAV_end47:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_48--------------------------------*/
//#ifdef WAV_48
//	.equiv WAV_size48, (WAV_end48 - WAV_start48)
//	.global WAV_start48
//	.global WAV_size48
//WAV_start48:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_48)
//	.align 2, 0
//WAV_end48:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_49--------------------------------*/
//#ifdef WAV_49
//	.equiv WAV_size49, (WAV_end49 - WAV_start49)
//	.global WAV_start49
//	.global WAV_size49
//WAV_start49:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_49)
//	.align 2, 0
//WAV_end49:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_50--------------------------------*/
//#ifdef WAV_50
//	.equiv WAV_size50, (WAV_end50 - WAV_start50)
//	.global WAV_start50
//	.global WAV_size50
//WAV_start50:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_50)
//	.align 2, 0
//WAV_end50:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_51--------------------------------*/
//#ifdef WAV_51
//	.equiv WAV_size51, (WAV_end51 - WAV_start51)
//	.global WAV_start51
//	.global WAV_size51
//WAV_start51:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_51)
//	.align 2, 0
//WAV_end51:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_52--------------------------------*/
//#ifdef WAV_52
//	.equiv WAV_size52, (WAV_end52 - WAV_start52)
//	.global WAV_start52
//	.global WAV_size52
//WAV_start52:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_52)
//	.align 2, 0
//WAV_end52:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_53--------------------------------*/
//#ifdef WAV_53
//	.equiv WAV_size53, (WAV_end53 - WAV_start53)
//	.global WAV_start53
//	.global WAV_size53
//WAV_start53:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_53)
//	.align 2, 0
//WAV_end53:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_54--------------------------------*/
//#ifdef WAV_54
//	.equiv WAV_size54, (WAV_end54 - WAV_start54)
//	.global WAV_start54
//	.global WAV_size54
//WAV_start54:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_54)
//	.align 2, 0
//WAV_end54:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_55--------------------------------*/
//#ifdef WAV_55
//	.equiv WAV_size55, (WAV_end55 - WAV_start55)
//	.global WAV_start55
//	.global WAV_size55
//WAV_start55:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_55)
//	.align 2, 0
//WAV_end55:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_56--------------------------------*/
//#ifdef WAV_56
//	.equiv WAV_size56, (WAV_end56 - WAV_start56)
//	.global WAV_start56
//	.global WAV_size56
//WAV_start56:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_56)
//	.align 2, 0
//WAV_end56:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_57--------------------------------*/
//#ifdef WAV_57
//	.equiv WAV_size57, (WAV_end57 - WAV_start57)
//	.global WAV_start57
//	.global WAV_size57
//WAV_start57:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_57)
//	.align 2, 0
//WAV_end57:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_58--------------------------------*/
//#ifdef WAV_58
//	.equiv WAV_size58, (WAV_end58 - WAV_start58)
//	.global WAV_start58
//	.global WAV_size58
//WAV_start58:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_58)
//	.align 2, 0
//WAV_end58:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_59--------------------------------*/
//#ifdef WAV_59
//	.equiv WAV_size59, (WAV_end59 - WAV_start59)
//	.global WAV_start59
//	.global WAV_size59
//WAV_start59:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_59)
//	.align 2, 0
//WAV_end59:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_60--------------------------------*/
//#ifdef WAV_60
//	.equiv WAV_size60, (WAV_end60 - WAV_start60)
//	.global WAV_start60
//	.global WAV_size60
//WAV_start60:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_60)
//	.align 2, 0
//WAV_end60:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_61--------------------------------*/
//#ifdef WAV_61
//	.equiv WAV_size61, (WAV_end61 - WAV_start61)
//	.global WAV_start61
//	.global WAV_size61
//WAV_start61:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_61)
//	.align 2, 0
//WAV_end61:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_62--------------------------------*/
//#ifdef WAV_62
//	.equiv WAV_size62, (WAV_end62 - WAV_start62)
//	.global WAV_start62
//	.global WAV_size62
//WAV_start62:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_62)
//	.align 2, 0
//WAV_end62:
//#endif
///*----------------------------------------------------------------------*/
//
///*--------------------------------WAV_63--------------------------------*/
//#ifdef WAV_63
//	.equiv WAV_size63, (WAV_end63 - WAV_start63)
//	.global WAV_start63
//	.global WAV_size63
//WAV_start63:
//	.incbin MACRO_TOSTRING(WAV_LINKER_PATH/WAV_63)
//	.align 2, 0
//WAV_end63:
//#endif
///*----------------------------------------------------------------------*/

#endif
