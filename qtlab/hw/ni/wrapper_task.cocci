@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxStartTask";
identifier taskHandle;
@@

-int32 fn(TaskHandle taskHandle)
+void fn()
{
+emit started();
+DAQmxErrChk(fn(task));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxStopTask";
identifier taskHandle;
@@

-int32 fn(TaskHandle taskHandle)
+void fn()
{
+emit stopped();
+DAQmxErrChk(fn(task));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxClearTask";
identifier taskHandle;
@@

-int32 fn(TaskHandle taskHandle)
+void fn()
{
+DAQmxErrChk(fn(task));
+task = nullptr;
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
@@

-int32 fn(TaskHandle taskHandle)
+void fn()
{
+DAQmxErrChk(fn(task));
}

@@
typedef TaskHandle;
identifier fn =~ "DAQmxIsTaskDone*";
identifier taskHandle;
type t1;
identifier i1;
@@
-int32 fn(TaskHandle taskHandle, t1 *i1)
+t1 fn()
{
+
+t1 __temp__;
+DAQmxErrChk(fn(task, &__temp__));
+return __temp__;
+
}

@@
typedef TaskHandle;
identifier fn =~ "DAQmxGet*";
identifier taskHandle;
type t1;
identifier i1;
@@
-int32 fn(TaskHandle taskHandle, t1 *i1)
+t1 fn()
{
+
+t1 __temp__;
+DAQmxErrChk(fn(task, &__temp__));
+return __temp__;
+
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1;
identifier i1;
@@
-int32 fn(TaskHandle taskHandle, t1 i1)
+void fn(t1 i1)
{
+DAQmxErrChk(fn(task, i1));
}

@@
typedef TaskHandle;
typedef uInt32;
typedef QString;
identifier fn;
identifier taskHandle;
identifier data =~ "data", bufferSize =~ "bufferSize";
@@
-int32 fn(TaskHandle taskHandle, char *data, uInt32 bufferSize)
+QString fn()
{
+
+char buf[256];
+DAQmxErrChk(fn(task, buf, 256));
+QString s;
+s+=buf;
+return s;
+
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2;
identifier i1, i2;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2)
+void fn(t1 i1, t2 i2)
{
+DAQmxErrChk(fn(task, i1, i2));
}

@@
typedef TaskHandle;
typedef uInt32;
typedef QString;
type t1;
identifier fn;
identifier taskHandle;
identifier i1, data =~ "data", bufferSize =~ "bufferSize";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, char *data, uInt32 bufferSize)
+QString fn(t1 i1)
{
+
+char buf[256];
+DAQmxErrChk(fn(task, i1, buf, 256));
+QString s;
+s+=buf;
+return s;
+
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3;
identifier i1, i2, i3 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 *i3)
+void fn(t1 i1, t2 i2)
{
+DAQmxErrChk(fn(task, i1, i2, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3;
identifier i1, i2, i3;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3)
+void fn(t1 i1, t2 i2, t3 i3)
{
+DAQmxErrChk(fn(task, i1, i2, i3));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4;
identifier i1, i2, i3, i4 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4)
+void fn(t1 i1, t2 i2, t3 i3)
{
+DAQmxErrChk(fn(task, i1, i2, i3, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4;
identifier i1, i2, i3, i4;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5;
identifier i1, i2, i3, i4, i5 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5;
identifier i1, i2, i3, i4, i5;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6;
identifier i1, i2, i3, i4, i5, i6 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6;
identifier i1, i2, i3, i4, i5, i6;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6));
}


@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7;
identifier i1, i2, i3, i4, i5, i6, i7 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 *i7)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, nullptr));
}


@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7;
identifier i1, i2, i3, i4, i5, i6, i7;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8;
identifier i1, i2, i3, i4, i5, i6, i7, i8 =~ "reserved";
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8;
identifier i1, i2, i3, i4, i5, i6, i7, i8;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14, t15 i15)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14, t15 i15)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
identifier taskHandle;
type t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16;
identifier i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16;
@@
-int32 fn(TaskHandle taskHandle, t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14, t15 i15, t16 i16)
+void fn(t1 i1, t2 i2, t3 i3, t4 i4, t5 i5, t6 i6, t7 i7, t8 i8, t9 i9, t10 i10, t11 i11, t12 i12, t13 i13, t14 i14, t15 i15, t16 i16)
{
+DAQmxErrChk(fn(task, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16));
}
