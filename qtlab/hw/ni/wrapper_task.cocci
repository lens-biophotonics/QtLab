@rule1@
typedef TaskHandle;
typedef int32;
identifier th, fn;
parameter list[n] PL;
expression list EL;
@@
int32 fn(TaskHandle th, PL@EL) {
...
}

@ script:python foo @
fn_stripped;
fn << rule1.fn;
@@
temp = fn
if fn.startswith('DAQmx'):
    temp = fn[5:]
    temp = temp[0].lower() + temp[1:]
coccinelle.fn_stripped = temp

@rule2 disable all@
identifier foo.fn_stripped, rule1.fn, rule1.th;
parameter list[n] rule1.PL;
expression list rule1.EL;
typedef NITask;
@@
-int32 fn(TaskHandle th, PL@EL)
+void fn_stripped(PL)
{
+DAQmxErrChk(fn(task, EL));
}

@@
@@
void startTask() {
...
+ emit started();
}

@@
@@
void stopTask() {
...
+ emit stopped();
}

@@
@@
void clearTask() {
...
+ task = nullptr;
}

@@
identifier fn =~ "get.*|isTaskDone";
type t1;
identifier i1;
parameter list[n] PL;
@@
-void fn(PL, t1 *i1)
+t1 fn(PL)
{
+t1 i1[1];
...
+return i1[0];
}

@@
type t1;
identifier i1 =~ "reserved";
identifier fn;
parameter list[n] PL;
expression list EL;
@@
-fn(PL@EL, t1 *i1)
+fn(PL)
{
+t1 *i1=nullptr;
...
}

@@
type t1;
identifier i1;
identifier bufferSize =~ "bufferSize";
identifier fn =~ "get*";
parameter list[n] PL;
expression list EL;
typedef QString;
@@
-void fn(PL@EL, char *i1, t1 bufferSize)
+QString fn(PL)
{
+char i1[256];
+t1 bufferSize=256;
...
+QString s;
+s+=i1;
+return s;
}

@@
type t1;
identifier i1;
identifier bufferSize =~ "bufferSize";
identifier fn =~ "get*";
parameter list[n] PL;
expression list EL;
@@
-void fn(PL@EL, char i1[], t1 bufferSize)
+QString fn(PL)
{
+char i1[256];
+t1 bufferSize=256;
...
+QString s;
+s+=i1;
+return s;
}

@@
identifier fn =~ "get.*TrigEdge";
typedef NITask::Edge;
expression E1;
@@
-int32 fn()
+NITask::Edge fn()
{
...
-return E1;
+return (NITask::Edge)E1;
}

@@
identifier i1 =~ "data", fn =~ "set.*";
identifier fn2;
@@
fn(
...,
-const char *i1
+QString i1
,...
  )
{
...
fn2(
...,
-i1
+i1.toLatin1()
,...
   )
...
}

@@
identifier fn, fn2;
identifier i1;
@@
fn(
...,
-const char i1[]
+QString i1
,...
  )
{
...
fn2(
...,
-i1
+i1.toLatin1()
,...
   )
...
}

@@
type t1;
identifier fn;
@@
-t1
+t1 __NITask__
fn(...) {...}
