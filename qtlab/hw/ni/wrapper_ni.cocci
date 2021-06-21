@rule1@
typedef int32;
identifier fn;
parameter list[n] PL;
expression list EL;
@@
int32 fn(PL@EL) {
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
identifier foo.fn_stripped, rule1.fn;
parameter list[n] rule1.PL;
expression list rule1.EL;
typedef NITask;
@@
-int32 fn(PL@EL)
+void fn_stripped(PL)
{
+DAQmxErrChk(fn(EL));
}

@rule3@
typedef uInt32;
identifier fn =~ "getDev..PhysicalChans|getDev..Lines|getDevTerminals";
typedef QStringList;
parameter list[n] PL;
expression list EL;
@@
void fn(PL@EL) {
...
}

@ script:python foo3 @
fn_original;
fn << rule3.fn;
@@
coccinelle.fn_original = 'DAQmx' + fn[0].upper() + fn[1:]

@@
identifier foo3.fn_original, rule3.fn;
identifier device =~ "device", data =~ "data", bufferSize =~ "bufferSize";
@@
-void fn(const char device[], char *data, uInt32 bufferSize)
+QStringList fn()
{
-...
+return getList(fn_original);
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
identifier data =~ "data";
identifier bufferSize =~ "bufferSize";
identifier fn =~ "get*";
parameter list[n] PL;
expression list EL;
@@
-void fn(PL@EL, char *data, t1 bufferSize)
+QString fn(PL)
{
+char data[2048];
+t1 bufferSize=2048;
...
+QString s;
+s+=data;
+return s;
}

@@
type t1;
identifier i1;
identifier fn =~ "get.*|.*Supports.*";
parameter list[n] PL;
expression list EL;
@@
-void fn(PL@EL, t1 *i1)
+t1 fn(PL)
{
+t1 i1[1];
...
+return i1[0];
}

@@
type t1;
identifier fn;
@@
-t1
+t1 __NI__
fn(...) {...}
