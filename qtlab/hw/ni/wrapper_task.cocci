@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxStartTask";
identifier th;
@@

-int32 fn(TaskHandle th)
+void fn()
{
+emit started();
+DAQmxErrChk(fn(task));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxStopTask";
identifier th;
@@
-int32 fn(TaskHandle th)
+void fn()
{
+emit stopped();
+DAQmxErrChk(fn(task));
}

@@
typedef TaskHandle;
typedef int32;
identifier fn =~ "DAQmxClearTask";
identifier th;
@@
-int32 fn(TaskHandle th)
+void fn()
{
+DAQmxErrChk(fn(task));
+task = nullptr;
}

@@
typedef TaskHandle;
identifier fn =~ "DAQmxIsTaskDone*";
type t1;
identifier th, i1;
@@
-int32 fn(TaskHandle th, t1 *i1)
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
type t1;
identifier th, i1;
@@
-int32 fn(TaskHandle th, t1 *i1)
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
typedef uInt32;
typedef QString;
identifier fn;
identifier th;
parameter list[n] PL;
expression list EL;
identifier data =~ "data", bufferSize =~ "bufferSize";
@@
-int32 fn(TaskHandle th, PL@EL, char *data, uInt32 bufferSize)
+QString fn(PL)
{
+
+char buf[256];
+DAQmxErrChk(fn(task, EL, buf, 256));
+QString s;
+s+=buf;
+return s;
+
}

@@
typedef TaskHandle;
typedef int32;
identifier fn;
parameter list[n] PL;
expression list EL;
type t1;
identifier th, i1 =~ "reserved";
@@
-int32 fn(TaskHandle th, PL@EL, t1 i1)
+void fn(PL)
{
+DAQmxErrChk(fn(task, EL, nullptr));
}

@@
typedef TaskHandle;
typedef int32;
identifier th, fn;
parameter list[n] PL;
expression list EL;
@@
-int32 fn(TaskHandle th, PL@EL)
+void fn(PL)
{
+DAQmxErrChk(fn(task, EL));
}
