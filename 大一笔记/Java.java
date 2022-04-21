java 



1.
//Java中的函数也叫做方法 方法逻辑意义代表的就是一个事物可以执行的操作
class Triangle
{
	int a;
	int b;
	int c;

	int zhouchang()  //不需要形参定义，因为zhouchang函数和属性a b c就在上头
	{
		return a + b + c;
	}

	double area()
	{
		double p = 1.0 + (a + b + c) / 2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
}

class hello    //这里的是文件的名字
{
	public static void main(String[] args)
	{
		Triangle s = new Triangle();
		s.a = 3;
		s.b = 4;
		s.c = 5;

		System.out.printf("%d   %f",s.zhouchang(), s.area());   //在Java中double和float都用%f输出
	}
}

============================================================================
Java语言的基本要素——标识符
1.标识符是以字母，下划线，美元符开始的第一个字符序列，后面可以跟字母，下划线，美元符，数字
  //括号里面是所占的字节数 boolean只占一个字节
2.%d   			  int 4 , long int 8, short 2, byte 1
  %x %#x %X %#X   int , long int  (x是大写，输出来就是大写，x是小写，输出来就是小写)
  %c  			  char 2
  %f  			  float 4, double 8
  %s  			  String
  '\u4e2d'        u是Unicode编码下4e2d所对应的字符，是中
  
基本数据类型：byte short int long float double boolean char
引用数据类型：String.class       SUN提供的
			  System.class		 SUN提供的
			  Student  		     程序员自己定义的
			  User.class		 程序员自己定义的
			  Product.class	     程序员自己定义的
			  Customer.class	 程序员自己定义的
			  
			  Java语言中所有的class都数以引用数据类型
3.字面值
-一眼看上去就知道是多少的数据，就是字面值
-字面值本质：
	字面值是有数据类型的
	    整型 100
		浮点型 3.14
		布尔型 true/false
		字符型 'a'
		字符串型 "hello"
	
	在内存中占用空间
	
	字面值就是内存中的一块空间，这块空间有类型， 有值
	
	只有字面值内存无法得到重复利用
	
	
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
  一个整型变量默认是int类型，如果数字过大，则必须要在末尾加L
  一个实数默认的是double类型，如果是float类型，得在后边加f （例如：float x = 2.2f;）
  字符常量
		必须用单引号括起来
		Java中字符和字符串都用Unicode编码表示
		在Unicode编码中一个字符占【两】个字节 如果是'张'这两个字节都有数据  如果是'a'后面一个字节有数据，前面一个字节没有数据
  可以把低精度转化成高精度，这样才不会丢失数据
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
布尔类型
1.用boolean表示，不能写成bool
2.布尔类型数据只有两个值true和false，且他们不对应于任何整数值
3.boolean b = true;
4.布尔类型只能参与逻辑关系运算 && || == != !
5.注意  if while for 中进行真假判断时只能使用逻辑表达式		

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
算术运算符
1.+可以表示字符串的连接   如："123" + "abc" = "123abc"
2.+还能把非字符串转化成字符串   如："x" + 123;的结果是"x123"

public class hello
{
	public static void main(String[] args)
	{
		//println以文本信息输出
		System.out.println(123);
		System.out.println("asda");
		System.out.println(6.66);
		System.out.println('A');
		System.out.println(3 + 1);
		
		System.out.println('a' + 1);  //字符输出就是它的Unicode码
		System.out.println("" + 'a' + 1); //字符串会把后面的字符都变成字符串
	}
}

输出结果：
123
asda
6.66
A
4

98
a1

3.取余运算符%  两边可以是小数
4.位运算符
右移 >>
    在右移时，符号位将随同移动，当为正数时，最高位0，最高位补0，而为负数时，最高位为1，最高位补1
>>>
    无论最高位为0还是1，左边移空的改为都补0

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
cmd书写格式
打开是cd
C:\Users\小可爱\Desktop>javac hello.java

C:\Users\小可爱\Desktop>java hello

可以输出汉字
C:\Users\小可爱\Desktop>javac -encoding utf-8 hello.java
C:\Users\小可爱\Desktop>java hello

javac -encoding UTF-8 hello.java

exit退出
想看一下当前路径下有哪些文件 dir 回车 
cls清屏
d:回车 —— 进入到d盘下
cd\替换路径  直接成为C:\>
cd C:\Users\小可爱\Documents\MyJava 切换到这个路径  切换到cd之后的路径
原来 C:\>
绝对路径：cd c:/windows
相对路径：cd WINDOWS  相对路径，是相对当前而言， 就是在c盘下必须有一个叫WINDOWS的
cd..可以回到上一级目录下 ，就是在每一个文件夹内都有一个..， 只是你看不见，就是这个可以回到上一级目录下
cd.可以配环境变量
查看本机的ip地址  ipconfig
ipconfig /all 查看详细的ip地址

classPath没配  在当前路径下寻找 classPath配好了 从配好的路径中去找
class的配置过程 我的电脑-右键-属性-高级-环境变量-用户变量-新建-变量名（CLASSPATH）-变量值
（就是C:\Users\小可爱\Documents\MyJava\javaProject\Java-SE\chapter-01）这条路径
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
*************
面向对象编程
*************
1.对象：目前正在使用new运算符在堆内存中开辟的空间为对象
2.引用是一个变量，不一定是局部变量，还可能是成员变量，引用保存了内存地址，指向了堆内存当中的对象
3.所有访问实例相关的数据，都需要通过引用.的方式访问，因为只有通过引用才能找到对象
4.只有一个空的引用，访问对象的实例相关数据才会出现空指针异常
5.啥是实例变量了：就是一个对象的参数名
  啥是局部变量了：就是这个对象所要干的动作里面的参数名，就是类函数里面的函数的参数，局部变量只在方法中有效
class Student
{
	Computer com;   //com是一个引用 【实例变量】
	
	public static void dosome()
	{
		Computer cc;  //cc是一个引用  【局部变量】
	}
}
1.面向过程设计思想
		分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现
		以算法为核心
		自顶向下设计，要求一开始必须对问题有很深的了解
		将大问题转化为若干小问题来求解
		表现形式：用函数来作为划分程序的基本单位
		直接面向问题
		
  面向过程设计优点：
		易于掌握和理解，符合人们的思维习惯
		对于需求明确，规模不大、变动较小的问题非常适合
		
  面向过程设计的缺点
		数据和操作分离开，对数据与操作的修改变得很困难
		数据的安全性的不到保障
		程序架构依赖关系的不合理
			main函数依赖于子函数，子函数又依赖于更小的子函数，而子函数往往是细节的实现，这些实现是经常变动的，造成的结果就是：程序
			的核心逻辑依赖于外延的细节，一个细节上的小改动，会引起一系列的变动
		对于”需求不明确、变动较大、规模很大的问题“，显得力不从心
  面向对象的三大特征（封装 继承 多态）
  采用面向对象的方式开发一个软件，生命周期当中：
        面向对象的分析：OOA
		面向对象的设计：OOD
		面向对象的编程：OOP
		
2.属性
//student是一个类，代表了所有的学生对象，是一个学生模板
//当前类只描述学生的状态信息【属性】
public class student
{
	//属性【描述的是对象的状态信息】
	//属性通常是采用变量的方法来定义
	//在类体当中，方法体之外定义的变量被称为”成员变量“
	//成员变量没有赋值，系统赋默认值：一切向0看齐
	//对象又被称为实例，实例变量又被称为对象变量
	
	int no;        no是一个实例变量，下面的这些变量都是实例变量
	String name;   String也是一个引用数据类型，就是分配的内存是堆内存 name保存的就是”bag“的地址，name是一个引用
	int age;
	boolean sex;
	String addr;
	
	
	//方法是描述对象的动作信息
}

pubic class OOTes
{
	public static void main(String[] args)
	{
		//通过一个类可以实例化N个对象
		//实例化对象的语法：new 类名()
		//new运算符的作用是创建对象，在JVM堆内存中开辟新的内存空间
		//方法区内存：在类加载的时候，class字节码代码被加载到该内存当中
		
		student s = new Student();  //Student是一个引用数据类型
								    //s是一个变量名  s是保存了一个地址，这个地址保存了它的student对象的数据（堆内存），s是一个引用
									//new Student()是一个学生对象
	}
}



2.内存
  1）JVM（Java虚拟机）主要包括三块内存空间：栈内存、堆内存、方法区内存
  2）堆内存和栈内存各有一个，一个线程一个栈内存
  3）方法调用的时候，该方法所需要的内存空间在栈内存中分配，称为压栈，方法执行结束之后，该方法所属的内存空间释放，称为弹栈
  4）栈中主要储存的是方法体中的局部变量
  5）方法的代码片段以及整个类的代码片段都被储存到方法区内存当中，在类加载的时候这些代码片段会载入
  6）在程序执行过程中使用new运算符创建的Java对象，储存在堆内存当中，对象内部有实例变量，所以实例变量储存在堆内存当中
  7）变量分类
		·局部变量【方法体中声明】  在main函数中的就是局部变量
		·成员变量【方法体外声明】  状态是一个类的属性     动作是一个类的方法
				·实例变量【前面修饰符没有static】
				·静态变量【前面修饰符有static】
		/*
			静态代码块
			特点：随着类的加载而执行，只执行一次，并且优于主函数，用于给类进行初始化的
			
			class StaticCode
			{
				Static 
				{
					System.out.println("a");
				}
			}
			
			class StaticCodeDemo
			{
				static
				{
					System.out.println("b");
				}
				
				public static void main(String[] args)
				{
					new StaticCode();
					new StaticCode();
					System.out.println("over");
					
					StaticCode s = null;  //类加载没有意义，只有有对象才有意义，所以不加载
				}
				
				static
				{
					System.out.println("c");
				}
			}
			
			开始java staticCodeDemo 
			staticCodeDemo静态代码块被执行，输出bc
			接着执行new StaticCode();   这个satticcode代码块被执行，类加载输出a，因为这个类已经在了，所以不会再次加载
		
		*/		
		
  8）静态变量储存在方法区内存当中
  9）三块内存当中变化最频繁的是栈内存，最先有数据的是方法区内存，垃圾回收器针对的主要是堆内存
  10）方法区内存在类加载的时候使用，类加载中的static 变量  static 语句块{} static方法  顺序自上而下 意思就是现有static int i; 接下来才可以调用i
  
  /*
	Person p = new Person("zhangsan", 20);
	
	这句话都做了什么事情？
	1.因为new用到了Person.class,所以会先找到Person.class文件并加载到内存中
	2.执行该类中static代码块，如果有的话，给Person.class类进行初始化
	3.在堆内存中开辟空间，分配内存地址
	4.在堆内存中建立对象的特有属性，并进行默认初始化  （0 null之类）
	5.对对象进行显示初始化  成员变量  int i = 9; //就是给这个9初始化的过程
	7.对对象进行对应的构造函数初始化
	8.将内存地址赋给栈内存中的p变量
  
  */
  
  
  
  详解内存的分配：
	
	/*
		首先，java PersonDemo
		类加载PersonDemo代码块，由于main函数是static的，所以将这段代码的class代码放到方法区中
		因为要new Person("zhangsan", 20); 所以去方法区（方法区中储存所有的class 文件和 static ）寻找，发现没有Person，所以类加载Person
		将Person中所有的内容放到方法区内存，当new的时候，先将跟这个对象有关的成员非static放到堆内存中，并初始化变量，再进行显式初始化
		因为构造函数有name  age  都是局部变量，所以放到栈中，将传递过来的zhangsan  20给name和age赋值，将这两个值给在堆中的name和age赋值
		因为要求只是要完成初始化，所以完成，name和age出栈
		
		关于类中的static方法：涉及到变量都在栈中，如果只是输出啥啥啥，就不涉及栈，直接输出了
	
	*/
	class Person
	{
		private String name;
		private int age;
		private static String country = "cn";
		
		Person(String name, int age)
		{
			this.name = name;
			this.age = age;
		}
		
		public void setName(String name)
		{
			this.name = name;
		}
		
		public void speak()
		{
			System.out.println(this.name + "..." + this.age);
		}
		
		public static void showCountry()
		{
			System.out.println("country = " + country);
		}
	}
	
	
	class PersonDemo
	{
		public static void main(String[] args)
		{
			Person p = new Person("zhangsan", 20);
			p.setName("lisi");
		}
	}
		
2.类
		把一类事物的静态属性和动态可执行操作组合在一起所得到的这个概念就是类
		类是抽象的，用来模拟一类事物，是一个概念、
		一旦被定义，类的概念就永远存在了
		一个类主要描述的是  状态 + 动作
							状态是一个类的属性     动作是一个类的方法
        
		类就是设计图纸，对象就是设计出来的汽车
	
	类的定义
		class Person
		{
			int age;     //是类的属性，也叫类数据成员，也叫字段，也叫域
			void shout() //是方法，也叫类的数据成员  shout方法可以直接访问同一个类中的age变量
			{
				System.out.println("oh,my god!i am" +age);
			}
		}

       
		class A
		{
			int i;
			int j;
		}
		
		class TextMemo
		{
			public static void main(String[] arge)
			{
				A aa = new A(); //(A*)malloc(sizeof(A));
				//new A();在堆内存中分配了一块区域，被当作了A对象
				//aa本身的内存是在栈中分配的
				//堆中的地址赋给了aa
				//aa所指向堆中的内存，aa代表了堆中的内存
				//aa.i 代表：aa这个静态指针变量所指向的动态内存中的A对象的i这个成员
				//aa.j 代表：aa这个静态指针变量所指向的动态内存中的A对象的j这个成员
				aa.i = 10;
				aa.j = 20;
				
				System.out.printf("%d %d\n",aa.i,aa.j);
				
			}
		}
		
—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
参数传递
传递的永远都是变量中保存的那个值,只不过有时候这个值是一个字面值10，有的时候这个值是另一个java对象的内存地址0x1234
public class Test01
{
	public static void main(String[] args)
	{
		int i = 10;
		add(i);
		System.out.println("main -->" + i);  //10
	}
	
	public static void add(int i)  //这样传是传值
	{
		i++;
		System.out.println("main -->" + i);  //11 
	}
	
}
--------------------------------------------------
public class UserTest
{
	public static void main(String[] args) 
	{
		User u = new User(20); 
		add(u);
		System.out.println("add-->" + u.age);
	}      
	
	public static void add(User u)
	{
		u.age++;
		System.out.println("add-->" + u.age);
	}
}                                                                                  
class User
{
	int age;
	public User(int i)
	{
		age = i;
	}
}		
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
值传递
User u = 0x1234;
User u2 = u;   //u传递给u2，实际上只是将0x1234这个值赋值给u2，u和u2实际上是两个不同的局部变量，但是他们这两个变量指向堆内存中
			   //同一个java对象

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
访问控制符
class Triangle
{
	int a, b, c;    //如果不加访问控制符，默认是protected
	int zhouchang()
	{
		return a + b + c;
	}
	
	void set(int i, int j, int k)
	{
		a = i;
		b = j;
		c = k;
	}
	
	double area()
	{
		double p = 1.0 + (a + b + c) / 2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
}

class TestTriangle
{
	public static void main(String[] args)
	{
		Triangle t = new Triangle();
		有三种赋值的方法，下面这个注释掉的就是第一种赋值的方法
		//t.a = 3;
		//t.b = 4;
		//t.c = 5;
		
		第二种就是建立一个类，相当于遥控器上的按钮，把数据输进去，可以保护，会安全
		t.set(3, 4, 5);
		System.out.printf("%d %f\n", t.zhouchang(), t.area());
	——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————	
		第三种是类的构造函数
		特点：函数名和类名是相同的
			  不能有返回值
			  可以有参数，也可以没有参数
			  可以有多个
		说明：声明一个对象，系统首先为该对象分配内存，然后立即自动调用该对象的构造函数
		注意：
			  任何一个类对象被声明时一定会调用该类的构造函数
			  无论一个类有多少个构造函数，生成一个类对象时一定只会调用其中的某一个构造函数
			 
		构造函数的返回值问题
			  有返回值的函数(包括返回值为void的函数)都不是构造函数，都不会被类对象自动调用
			  当然也可以定义多个没有返回值的函数，注意连void都不可以加，这些函数才是构造函数，无返回值的函数才会被对象自动调用
			  如果定义了有返回值并且方法名与类名相同的方法，程序并不会报错，但容易产生歧义，所以强烈建议不要在构造方法前面加返回值
			  
		构造函数数据成员的赋值问题
			  如果在定义的时候不初始化，则它的值是系统自动分配好的默认值
			  如果在定义的时候同时赋初值，则是可以的，也就是说该值是有效的
			  如果在定义的同时赋初值，当然生效，但如果在构造函数中右改变了定义时赋的初值，则该数据成员最终的值就是构造函数中修改之后的那个值
			        因为：系统会先执行定义时赋的初值，然后再执行构造函数中赋的初值
					
			  当一个成员被创建时，会对其中各种类型的成员变量自动进行初始化赋值
			  如果是在main函数里的就是局部变量，必须得赋初始值
			  在类里的系统自动分配初始值
			  成员变量类型                         初始值
			  byte								     0
			  short									 0
			  int 									 0
			  long									 0L
			  float									0.0F
			  double								0.0D 
			  char								  '\u0000'  (表示为空)
			  boolean							   False
			  All reference type				    Null
		多个构造函数可能带来的冲突
		一旦编程者为类定义了构造方法，系统就不再提供默认的构造方法了
	————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
		构造函数在下面：
	}
}

类的访问控制符有四种
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
public
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
protect
本类，同一个包下，不同包下不行，但是子类中可以
可以通过外部访问的方式访问类内部的public成员
默认（不加任何修饰符）
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
缺省
本类，同一个包下，不同包下不行
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
private
不可以通过外部访问的方式访问内部的private成员
/*
 *面向对象的三大特征：
 * —封装
 * —继承
 * —多态
 * 
 * 当前主要讲的是封装机制，为什么要封装？封装有什么好处？
 * 封装的好处
 * 		1.封装之后，对于那个事物来说，看不到这个事物复杂的一面，只能看到事物简单的一面，
 *              复杂性封装，对外提供简单的操作入口，照相机就是一个很好的封装的案例，照相机的
 *              实现原理非常复杂，但是对于使用照相机的人来说，操作起来是非常方便的，不用关心
 *              内部的实现原理
 *      2.封装之后，才会形成真正的对象，真正的独立体
 *      3.封装就意为着以后的程序可以重复使用，并且这个事物适应性比较强，在任何场合都可以使用
 *      4.封装之后，对于事物本身，提高了安全性
 */

public class UserTest {
	
	public static void main(String[] args) 
	{
		User user = new User();
		System.out.println("该用户年龄：" + user.age);
		
		user.age = 20;
		System.out.println("该用户年龄：" + user.age);

		//这里的age属性显然是完全暴露给外部程序的，对于程序员来说可以操作User对象当中所有的细节
		//导致User中部分数据不安全，不建议这样，建议User类型进行封装，建议在外部程序中不能随意
		//访问User对象当中的程序，可以保证属性的安全
		user.age = -100;
		System.out.println("该用户年龄：" + user.age);
	}
}
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
在一个类的内部，所有的成员可以互相访问，访问控制符可以透明化，访问控制符是针对外部而言的

外部访问包括两种方式
	通过类名访问类内部的成员
	通过类对象名访问类内部的成员
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
	
构造函数：

/**
 *          构造方法的作用
 * 		1.创建对象
 * 		2.创建对象的同时，初始化实例变量的内存空间，给实例变量赋值
 * 
 * 成员变量之实例变量，属于对象级别的变量，这种变量必须先有对象才能有实例变量
 * 实例变量（存在堆的java对象的内部，类加载和堆没关系，只有new的时候才和堆有关系，new又和构造方法有关系）
 * 没有手动赋值 的时候，系统默认赋值，那么这个系统默认赋值是在什么时候完成的呢
 * 是在类加载的时候吗，不是，因为类加载的时候只是加载了代码片段，所以此时实例变量并没有初始化
 * 实际上，实例变量的内存空间是在构造方法（构造函数）执行过程中完成开辟的。完成初始化的
 * 系统在默认赋值的时候，也是在构造方法执行过程中完成的赋值。
 * */
 
 ——————————————————————————————————————————————————————————————————————————————————————————————————————————————
 构造函数中只能出现this关键字
 Person()
 {
	 
 }
 
 Person(String name)
 {
	 this();
	 this.name = name;
 }
 
 Person(String name, int age)
 {
	 this(name);   //如果初始化中还有初始化，要把这个初始化先执行  如果放在下一个语句的下面  ，会将实际的name值改变
	 this.name = name;
	 this.age = age;
 }

—————————————————————————————————————————————————————————————————————————————————————————————————————————————————
 //账户类
public class Account 
{
		//编号
		private String actno;  //实例变量/对象变量，也就是说，必须先有对象，才能有对应的实例变量，
	
		//余额
		private double balance;
		
		//无参数构造器:作用：创建对象    初始化实例变量的内存空间
		//如何生成一个构造方法：右键->source->using filed
				
		public Account(String actno, double balance) {
			//初始化实例变量的内存空间
			//actno = null;
			//balance = 0.0;
			super();
			this.actno = actno;
			this.balance = balance;
		}


		public String getActno() 
		{
			return actno;
		}
		public void setActno(String actno) 
		{
			this.actno = actno;
		}
		public double getBalance() 
		{
			return balance;
		}
		public void setBalance(double balance) 
		{
			this.balance = balance;
		}
		
}
 

public class UserTest
{
	public static void main(String[] args) 
	{
			//创建对象
	     	//如何查看它属于哪个属性和方法 按住ctrl键，鼠标移动到Accout，如果出现下划线，点过去，然后就会跳到你调用的方法
			//如果东西特别的多查看某个元素 ctrl + o，然后输入要查找的元素名称，该名称不一定输入全名称
	     	//ToggleBlockSeletionMode罚抄  块编辑
		    Account act1 = new Account("塔塔",45.7);
			//给对象的属性赋值                                                     
			//act1.setActno("111");                                                
			//act1.setBalance(45.6);                                               
		                                                                           
		                                                      
			System.out.println("账号：" + act1.getActno());                        
			System.out.printf("余额：" + act1.getBalance());                       
			                                                                       
			                                                                       
	}                                                                              
}                                                                                  

----------------------------------------------------------------------------------------------------------------------

class A
{
	private int i;
	private int j;
	
	/*public A()
	{
		System.out.printf("嘿嘿！\n\n");
	}*/
	
	public A(int a, int b)
	{
		i = a;
		j = b;
		System.out.printf("无参构造函数被调用了！\n");
	}
	
	public void show()
	{
		System.out.printf("i = %d, j = %d\n", i, j);
	}
}

class hello
{
	public static void main(String[] args)
	{
		A aa = new A(1,2);   
		/**
		      说明了构造函数直接先执行
			  public A(int a, int b)
				{
					i = a;
					j = b;
					System.out.printf("无参构造函数被调用了！\n");
				}
		**/
		
		//System.out.printf("%d %d\n", aa.i, aa.j);  //不能这样写，因为是私有的
		aa.show();
	}
}

*           关于java类中的构造方法
 * 			1.构造方法又被称为构造函数/构造器/construtor
 * 			2.构造方法语法结构：
 * 					（修饰符列表） 构造方法名（形式参数列表）
 * 					{
 *                  }
 *                  
 *                  public class User   //创建了一个类
 *                  {
 *                  		public User(int i)  //这个构造函数是包括在类里面的
 *                  		{
 *                  		
 *                  		}
 *                  }
 *          3.回顾普通方法的语法结构
 *          			（修饰符列表） 返回值列表 方法名（形式参数列表）
 *          			 {
 *          			 }
 *          4.对于构造方法来说，“返回值类型”不需要指定，并且也不能写void
 *                      只要写上void，就成为普通方法了
 *          
 *          5.对于构造方法来说，构造方法方法的方法名必须和类名保持一致。
 *          6.构造方法的作用？
 *                                构造方法存在的意义是，通过构造方法的调用，可以创建对象
 *          7.构造方法应该怎么调用？
 *          	            普通法方是这样调用的：方法修饰符中有static的时候          类名.方法名（实参列表） 
 *                                                                         方法修饰符中没有static的时候       引用.方法名（实参列表）
 *                               构造方法   构造方法名（实参列表）
 *          8.构造方法调用结束之后？
 *          	               每一个构造方法实际上执行结束之后都有返回值，但是这个return 值；这样的语句不需要写
 *                              并且 返回值类型是构造方法所在类的类型，构造方法结束的时候java程序自动返回值。并且
 *                              返回值类型是构造方法所在类的类型。由于构造方法的返回值类型就是类本身，所以返回值
 *                              类型不需要编写
 *         9.注释和取消注释：strl + /   多行注释ctrl + shift + /      
 *         10.当一个类中没有定义任何构造方法的话，系统默认给该类提供一个无参数的构造方法，这个构造方法被称为
 *                      缺省构造器  
 *         11.当一个类显示的构造方法定义出来了，那么系统不再默认为这个类提供缺省构造器，建议开发中手动
 *                     为当前类提供无参数的构造方法
 *        12.构造方法支持重载机制，在一个类当中编写多个构造方法，这多个构造方法显然已经构成方法重载机制。
 *        13.只要构造方法调用就一定会创建对象，并且一定是在堆内存中开辟空间
 *        User u1 = new User();    //User是一个构造方法的方法名，因为只有方法才带括号
 *        public class ConstructTest01{
 *               public static void main(String[] args) 
 *               {
 *        		User u1 = new User();
 *        		User u2 = new User(10);
 *        		User u3 = new User("zahngsan");
 *        		User u4 = new User(10, zhangsan);
 *        		
 *        		//调用带有static的方法，类名.
 *        		ConstructTest01.doSome();  //如何调用doSome
 *        		doSome();
 *        		
 *        		//调用没有带有static的方法，引用.
 *        		//doOther方法在ConstructTest01类中，所以需要创建ConstructTest01对象
 *        		//创建ConstructTest01对象，调用无参数构造方法
 *              ConstructorTest01 t = new ConstructorTest01(); //一个类中没有任何构造方法的话，系统默认提供一个无参构造器
 *        		t.doOther();
 *        		
 *        		}
 *        
 *        		public static void doSome()
 *        		{
 *        			System.out.println("do some");
 *        		}
 *        		
 *        		public void doOther()
 *        		{
 *        		}
 *        }
 *        
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
setter and getter

/*
 * 封装的步骤
 * 1.所有属性私有化，使用private关键字进行修饰，private表示私有的，修饰的所有数据只能在本类中访问
 * 2.对外提供简单的操作入口，也就是说外部程序要想访问age属性必须通过这些简单的入口进行访问
 * 		对外提供两个公开的方法，分别是get方法和set方法
 * 		想修改age属性，调用set方法
 * 		像读取age属性，调用get方法
 * 3.set方法的命名规范
 *      public void set + 属性名首字母大写（形参）
 *      {
 *      }
 *      
 *      public void setAge(int a)
 *      {
 *      	age = a;
 *      }
 * 4.get方法的命名规范
 *     public int getAge()
 *     {
 *     return age;
 *     } 
 *     
 * 回想一下，一个属性访问的时候包括几种访问形式
 *     第一种方式：读取这个属性的值，读取get
 *     第二种方式：修改这个属性的值，修改set
 *     
 *需要大家背会
 *   setter and getter 没有static关键字
 *     有static关键字修饰的方法怎么调用（类名 方法名（实参））  也可以使用引用.  但虽然是引用. 但java虚拟机还是使用的类名.
 *     没有static关键字修饰的方法怎么调用：引用 方法名 （实参）引用不一定是局部变量，husband里面的wife也是引用实例变量
 */
public class User {
	//属性私有化
	private int age;
	
	//set方法没有返回值，因为set方法只负责修改数据
	/*public void setAge(int age)
	{
		//age = age;  //java有就近原则，和private int age 没有关系，这里其实并没有给age属性赋值，这里的age都是局部变量
		
	}*/
	public void setAge(int a)
	{
		if(a < 0 || a > 150)
		{
			System.out.println("对不起，您提供的年龄不合法");
			return;
		}
		age = a;
	}
	
	
	//getter
	public int getAge()
	{
		return age;
    }
}

--------------------------------------------------------------------------------------------------------------------------------

//顾客类
public class bid {
	//属性
	private int id;
	private String name;
	private int age;
	private String addr;
	
	//setter and getter 方法
	//如何生成setter and getter方法  右键source -> generate setter and getter
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getAddr() {
		return addr;
	}
	public void setAddr(String addr) {
		this.addr = addr;
	}
	
}

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


====================================================================================================================================================
函数的重载
	同名函数通过不同的形参做类似的事情，这就叫做函数的重载
	函数重载要求
		函数的形参个数
		函数的形参顺序
		函数的形参数据类型
		这三个至少有一个是不一样的
	如果两个函数只是函数的返回值不一样，其他都一样，这构不成函数的重载，并且编译时会报错

class TestOver
{
	static int add(int a, int b)
	{
		return a + b;
	}
	
	static double add(int a, int b) //报错，参数列表一样，返回值不一样
	{
		return a + b;
	}
	
	static double add(double x, double y)
	{
		return x + y;
	}
	
	static int add(int a, int b, int c)
	{
		return a + b + c;
	}
	
	public static void main(String[] args)
	{
		System.out.printf("%d\n", add(1,2));
		System.out.printf("%f\n", add(1.7,2.8));
		System.out.printf("%d\n", add(1,2,3));
	}
}


====================================================================================================================================================
关键字this

this.方法名称:用来访问本类的成员方法
this();  访问本类的构造方法   ()中可以有参数的 如果有参数 就是调用指定的有参构造
注意事项:
				1.this() 不能使用在普通方法中 只能写在构造方法中
				2.必须是构造方法中的第一条语句

class A
{
	public int i;
	public A(int j)
	{
		i = j;
	}
	
	public void show()   //这个函数单独为它分配一块空间，每次输入一个指针变量，*this对这个指针变量处理，不用每次都为它分配空间，太占内存
	{
		System.out.printf("i = %d\n", i);    //这里的i就是(*this).i
	}
}



public class TestThis_1
{
	public staric void main(String[] args)
	{
			A aa1 = new A(10); 
			A aa2 = new A(20);
			aa1.show();   //aa1.show(aa1)
			aa2.show();   //aa1.show(aa2)
	}
}

是一个系统隐含的指针被自动附加在非静态的成员函数参数列表中
当前时刻，哪个对象调用该函数，那么this就指向当前调用函数的对象，系统会自动在该函数的参数列表中添加一个隐藏的this指针，并且把调用该函数
的对象的地址赋给this指针，这样一来，在函数内部通过this就可以访问当前正在调用该函数的对象的成员
静态函数内部，没有this指针

关键字this代表当前正在调用该方法的那个对象，具体可分为两种情况
在普通方法中，关键字this代表方法的调用者、即本次调用了该方法的对象
在构造方法中，关键字this代表了该方法本次运行所创建的那个新对象

aa1和aa2在内存中分别有各自的数据成员i，但是aa1和aa2公用show()方法，show方法如何知道输出的i是哪个对象中的i
每个非static方法中都隐含这个this指针，指向当前正在调用该方法的对象

class A
{
	public int i = 99;
	public A(int i)      //这是一个构造方法，在构造方法里this代表就是当前时刻正在创建的对象，就是构造函数
	{
		this.i = i;   //this代表目前正在创建的对象，把形参i的值赋给99所对应的i
		System.out.printf("%d\n", i);
	}
	public void show()  //这是一种普通方法
	{
		System.out.printf("%d", this.i);    //this代表目前正在调用show方法的对象，谁调用show方法，this就指向谁
	}
	
}
应用
class Student
{
	private String name;
	private int age;
	
	public Student(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	
	public void showInformation()
	{
		System.out.printf("name = %s, age = %d\n",this.name, this.age);
	}
}


====================================================================================================================================================
static  关键字
class A
{
	public static int i = 10;
	public void show()
	{
		System.out.printf("%d\n", i);
	}


class M
{
	public static void main(String[] args)
	{
		如果i之前加static，aa1、aa2、aa3的i值都变成20
		A aa1 = new A();
		A aa2 = new A();
		A aa3 = new A();
		
		aa1.i = 20;
		aa2.show();
	}
}





//本程序证明了：没有对象，我们仍然可以通过类名的方式访问该类内部的static属性
class A
{
	public static int i = 10;
}

class TestStatic_2
{
	public static void main(String[] arge)
	{
		System.out.printf("%d\n",A.i);
	}
}




//static属性和方法虽然属于类本身，虽然可以通过类名的方式访问，但static属性和方法很明显也属于类对象，当然也可以通过类对象名的方式访问
class A
{
	public static int i = 10;
	public static void f()
	{
		System.out.printf("i love anita");
	}
}

class TestStatic_2
{
	public static void main(String[] arge)
	{
		System.out.printf("%d\n",A.i);
		A aa = new A();
		A.f();
	}
}


//只有非private的static成员才可以通过类名的方式访问
//static只是表明了该成员具有了可以通过类名访问的特征，但是否可以通过类名访问，必须还满足一个条件，该成员必须是非private



class A
{
	private static int i = 10;
	public int j = 99;
	
	public static void f()
	{
		//g();  //ERROR 静态方法不可以访问非静态成员，静态可能没有对象
		System.out.printf("FFFF\n);
		//j = 22;  //也是错误的
	}
	
	public void g()
	{
		//f();   //OK  说明非静态方法可以访问静态成员
		System.out.printf("FFFFF\n");
		System.out.printf("%d\n", i);
	}
}


public（公有的） private（私有的） protect（默认的，不加任何修饰符）  别人能不能用
static 静态的   是不是和这个类粘连在一起的
this

class A
{
	priavte int i;
	private static int cnt = 0
	
	public A()
	{
		++cnt;
	}
	
	public A(int i)
	{
		this.i = i;
		++cnt;
	}
	
	public static int getCnt()
	{
		//return 返回的是A对象的个数
		return cnt;   //静态的是属于类的，没有对象
	}
	
}
public class hello
{
	public static void main(String[] arge)
	{
		System.out.printf("当前时刻A对象的个数是：%d\n", A.getCnt);   //这个是0个
		A aa1 = new A();
		System.out.printf("当前时刻A对象的个数是：%d\n", A.getCnt);   //这个是1个
		A aa2 = new A();
		System.out.printf("当前时刻A对象的个数是：%d\n", A.getCnt);   //这个是2个
	}
}


class A
{
	public int i = 20;
	private static A aa = new A();   //aa是否是A对象的属性
	private A()
	{
		
	}
	public static A getA()   //static一定是不能省略的，
	{
		return aa;
	}
}

public class TestStatic_2
{
	public static void main(String[] args)
	{
		A aa1 = new A();   //如果A类的构造方法是私有的，则new A()就会报错
		A aa2 = new A();
	}
}


---------
面向对象和面向过程的区别（盖饭，蛋炒饭）
面向对象的三大特征
类和对象的概念
类的定义
对象的创建和使用
面向对象的封装性
构造函数（构造方法，构造器）
对象和引用
-------
实例变量得先创建对象

====================================================================================================================================================
单例模式初步
1.设计模式定义：可以重复利用的解决方案
2.设计模式从结构上分为三类
   ·创建型
   ·结构型
   ·行为型
3.最简单的设计模式就是单例，单例这种模式尽量少用，也有将其称为”反模式“
4.好处：对象实例创建完成后，会放到堆中，如果堆中的实例过多，将会存在特别多的垃圾，这样会导致一些问题，如内存溢出等，使用单例模式后
  ，只会创建一个实例，显著减少对象实例的个数，同时也会提高性能，因为不会频繁的创建对象
  
  为了保证JVM中某一个类型的java对象永远只有一个
  
5.单例模式的三要素：
   ·在类体中需要有静态的私有的本类型的变量
   ·构造方法必须是私有的
   ·提供一个公共的静态的入口点方法
   
   
6.单例模式要领
   ·构造方法私有化
   ·对外提供一个公开的静态的获取当前类型对象的方法
   ·提供一个当前类型的静态变量
   
7.单例模式分为两种
   ·饿汉式单例：在类加载阶段就创建了对象
   ·懒汉式单例：用到对象的时候才会创建对象
   
   
//懒汉式单例
public class Singleton
{
	
	//必须是静态变量，因为访问是在静态方法中访问的
	private static Singleton s;
	
	//将构造方法私有化
	private Singleton()
	{
		
	}
	
	//对外提供一个公开获取Singleton对象的方法
	public static Singleton getInstance()
	{
		if (s == null)
		{
			s = new Singleton();
		}
		return s;
	}
}


//饿汉式单例模式
public class Customer
{
	//类加载的时候只执行一次
	private static Customer c = new Customer();
	
	//构造方法私有化
	private Customer() {}
	
	//提供公开的方法
	public static Customer getInstance()
	{
		return c;
	}
}

public class Test01
{
	public static void main(String[] args)
	{
		Singleton s1 = Singleton.getInstance();
		Singleton s2 = Singleton.getInstance();
	}
}

===================================================================================================================================================
继承
1.引入继承最基本的作用是：代码重用
2.语法：
	【修饰符列表】 class 子类名 extends 父类名
	{
		
	}
  java语言中，类和类之间只支持单继承
  一个类如果没有显示继承其他类，则该类默认继承objects，objects是SUN提供的根类
  例：
  /*
	objects中有toString()
  */
  public class Customer
  {
	  public static void main(String[] args)
	  {
		  Customer c = new Customer();
		  String s = c.toString();
		  System.out.println(s);
	  }
  }
  
3.实例
public class Sub extends Super
{
	public void m3()
	{
		System.out.println("m3...");
	}
}

public class Super
{
	public void m1()
	{
		System.out.println("m1...");
	}
	
	public void m2()
	{
		System.out.println("m2...");
	}
}


4.
java语言中子类继承父类，会将父类中所有的数据全部继承，包括私有的也能继承过来，
但是在子类中无法直接访问父类中的私有的数据，但是可以间接访问
（就是建立一个setter getter方法）
注意：构造方法无法被子类继承


===================================================================================================================================================
方法的覆盖
1.方法的覆盖的条件
	·必须要有继承关系-发生在具有继承关系的两个类之间
	·覆盖只能出现在子类中，如果没有继承关系，不存在覆盖，只存在重载
	·在子类中被覆盖的方法，必须和父类中的方法完全一样，也就是方法名，返回类型，参数列表完全一样
	·子类方法的访问权限不能小于父类方法的访问权限 例如父类public 子类private
	·子类方法不能抛出比父类方法更多的异常，但可以抛出父类方法异常的子异常
	·父类的静态方法不能被子类覆盖
	·父类的私有方法不能覆盖
	·覆盖指的是成员方法，和成员变量无关
	·构造方法无法被覆盖，因为构造方法无法被继承
	
	
2.
/*
	关于方法的覆盖：
	
	1.什么时候方法要进行重写？
		如果父类中的方法已经无法满足当前子类的业务需要需要将父类中的方法进行重新写一遍
	
	2.子类如果重写父类中的方法之后，子类对象一定调用的是重写之后的方法

*/

public class Test01
{
	public static void main(string[] args)
	{
		//创建子类对象
		Cat c = new Cat();
		
		//调用方法
		c.move();
	}
}

//父类：动物
class Animal 
{
	public void move()
	{
		System.out.println("动物在移动！");
	}
}

//子类：猫
class Cat extends Animal
{
	//Cat中的move方法应该输出：猫在走猫步
	//Animal中的move方法已经无法满足Cat了
	//所以要再Cat类中对Animal类中的move方法进行重新定义（方法的覆盖，方法的重写，Overwrite，OVerride）
	public void move
	{
		System.out.println("猫在走猫步！");
	}
}

===================================================================================================================================================
多态
1.
/*
	关于java语言中向上转型和向下转型
		1.向上转型（upcasting）：子->父
		2.向下转型（downcasting）:父->子
		
	注意：无论是向上转型还是向下转型，两个类之间必须要有继承关系
	成员变量看左边  函数调用看右边

*/

public class Test02
{
	public static void main(String[] args)
	{
		//向上转型又被称为自动类型转换
		//父类型的引用指向子类型的对象
		//程序分为两个阶段：编译阶段、运行阶段
		//程序在编译阶段只知道a1是一个animal类型
		//程序在运行的时候队中的实际对象是Cat类型
		Animal a1 = new Cat();
		
		//程序在编译阶段a1被编译器看作Animal类型
		//所以程序在编译阶段a1引用绑定的是Animal类中的eat方法（静态绑定）
		//程序在运行的时候队中的对象实际上是Cat类型，而Cat已经重写了eat方法
		//所以程序在运行阶段对象的绑定的方法是Cat中的eat方法（动态绑定）
		a1.eat();
		
		//向下转型：强制类型转换
		Animal a2 = new Cat(); //向上转型
		
		//要执行move方法，怎么做？
		//只能强制类型转换，需要加强制类型转换符
		Cat c1 = (Cat)a2;
		c1.move;
		
		//判断以下程序运行的时候会出现什么问题？
		//Animal a3 = new Dog(); //向上转型
		
		//强制类型转换
		//Cat c2 = (Cat)a3;  //java.lang.ClassCastException
		
		//在做强制类型转换的时候程序是存在风险的
		//为了避免ClassCastException的发生，java引入了instanceof
		
		/**
			用法
				1.instanceof运算符的运算结果是boolean类型
				2.（引用 instanceof 类型） -- >true / false
					例如：（a instanceof Cat）如果结果是true表示，a引用指向队中的java对象是Cat类型
		**/
		
		Animal a3 = new Dog();
		
		System.out.println(a3 instanceof Cat); // false
		
		//推荐：在做向下转型的额时候要使用instanceof运算符判断，避免ClassCastException
		if(a3 instanceof Cat)
		{
			Cat c2 = (Cat)a3;
		}
	}
}

class Animal
{
	public void eat()
	{
		System.out.println("动物在吃！");
	}
}


class Dog extends Animal
{
	public void eat()
	{
		System.out.println("狗");
	}
}


class Cat extends Animal
{
	public void eat()
	{
		System.out.println("猫吃鱼");
	}
	
	public void move()
	{
		System.out.println("猫走猫步！");
	}
}


2.使用多态的好处：使用多态可以使代码之间的耦合度降低，项目的扩展能力增强
public class Test01
{
	public static void main(String[] args)
	{
		//创建主人
		Person zhangsan = new Person();
		
		//创建宠物
		Dog d = new Dog();
		Cat c = new Cat();
		
		//喂
		zhangsan.feed(d);
		zhangsan.feed(c);
	}
}

class Person
{
	/*
	//喂养
	public void feed(Dog d)
	{
		d.eat();
	}
	
	//因为用户的业务改变了，所以软件要升级
	public void feed(Cat c)
	{
		c.eat();
	}
	*/
	
	//以上的代码得出，Person类型的扩展能力太差
	//尽量不要面向具体变成，面向父类型编程，面向抽象编程
	public void feed(Animal a)
	{
		a.eat();
	}
}

class Cat extends Animal
{
	public void eat()
	{
		System.out.println("猫吃东西！");
	}
}



class Dog extends Animal
{
	public void eat()
	{
		System.out.println("狗吃东西");
	}
}

class Animal
{
	public void eat() {}
}


===================================================================================================================================================
super
1.super不是引用类型，super中储存的不是内存地址，super指向的不是父类对象
2.super代表的是当前子类对象的父类型特征
3.什么时候使用super
	子类和父类中都有某个数据，例如，子类和父类中都有name这个属性，如果要在子类中访问父类中的name属性，需要使用super
4.super可以用在什么地方
	第一：super可以用在成员方法中，不可以用在静态方法中
	第二：super可以用在构造方法中
	super相当于父类对象
	super();相当于调用父类构造方法
	
	
//经理
public class Manager extends Employee
{
	String name = "李四";
	
	//子类将父类中的work方法重写了
	public void work()
	{
		System.out.println("经理在工作");
	}
	
	//成员方法
	public void m1()
	{
		super.work();
		
		System.out.println(this.name);
		System.out.println(name);
		System.out.println(super.name);
	}
	
	/*
		this和super相同，都不能用在静态上下文中。
		public static void m1()
		{
			System.out.println(super.name);
		}
	*/
}

public class Employee
{
	String name = "张三";
	
	//成员方法
	public void work()
	{
		System.out.println("员工在工作");
	}
}


public class Test01
{
	public static void main(String[] args)
	{
		Manager m = new Manager();
		
		m.m1();
	}
}


5.
在java语言中只要使创建java对象，那么object中的无参数构造方法一定会执行

单例模式的缺点：
	1.构造方法私有化
	
public class DebitAccount extends Account
{
	//Field
	//独特属性
	private double debit;
	
	//Constructor
	public DebitAccount()
	{
		//super();   //我懂了，为什么默认会有super()  调用父类无参构造方法，创造父类对象，之后才可以调用父类中的方法，变量之类
	}
	
	public DebitAccount(string actno, double balance, double debit)
	{
		//通过子类的构造方法去调用父类的构造方法，作用是，给当前子类对象中的父类型特征赋值
		super(actno, balance);
		this.debit = debit;
	}
	
	public void setDebit(double debit)
	{
		this.debit = debit;
	}
	
	public double getDebit()
	{
		return debit;
	}
}


public class Account extends Objects
{
	private String actno;
	private double balance;
	
	public Account()
	{
		//super();
		System.out.println("Account 的无参数构造方法被执行");
	}
	
	public Account(String actno, double balance)
	{
		//为什么之前会默认super呢，我觉得有对象，就得有对象所对应的变量，这些变量在构造方法执行的时候得全部初始化
		//可是从父亲那里继承来的无法初始化，所以super对应父亲的无参数构造方法，如果是super(9,0) ,就对应父亲有参数的构造方法
		//super();
		this.actno = actno;
		this.balance = balance;
	}
	
	//setter and getter
	public void setActno(String actno)
	{
		this.actno = actno;
	}
	
	public String getActno()
	{
		return actno;
	}
	
	public void setBalance(double balance)
	{
		this.balance = balance;
	}
	
	public String getBalance(double balance)
	{
		return balance;
	}
}


public class Test02
{
	public static void main(string[] args)
	{
		DebitAccount da = new DebitAccount();
	}
}

===================================================================================================================================================
final 关键字
/*
	final修饰的类无法被继承
*/
final class A()

class B extends A()

//final修饰的方法无法被覆盖
class A
{
	public final void m1() {}
}

class B extends A 
{
	public void m1() {}
}


//final修饰的局部变量，一旦赋值，不可再改变
class A
{
	public void m1()
	{
		//声明
		final int i;
		
		//第一次赋值
		i = 100;
		
		//不能重新赋值
		i = 1200;
	}
}

//final修饰的成员变量必须显示的初始化
class A
{
	final int i = 100;
	final int k;
	A()
	{
		k = 200;
	}	
}

class MyMath
{
	//常量：java中要求所有的常量大写
	//常量：只不可再改变的变量
	public static final double PI = 3.14;
}

===================================================================================================================================================
abstract
1.如何定义抽象类？
	class关键字前加abstract
2.抽象类无法被实例化
3.虽然抽象类没有办法被实例化，但是抽象类也有构造方法，该构造方法是给子类创建对象用的
  /*
		abstract class A
		{
			public A()
			{
				System.out.println("ABH");
			}
			
			public void B()
			{
				System.out.println("B被调用了");
			}
		}

		class OMG extends A
		{
			OMG()
			{
				super.B();
				System.out.println("OMG被调用了");
			}
		}


		public class Test01
		{
			public static void main(String[] args) throws Exception
			{
				OMG h = new OMG();
			}
		}
		
		看看上面这个程序，抽象类中的非静态方法可以被子类调用，这就是构造方法存在的意义
  */
4.抽象类中可以定义抽象方法
	抽象方法的语法，在方法的修饰符列表中添加abstract关键字，并且抽象方法应该以;结束，不能带有{}
	例如： public abstract void m1();
	
5.抽象类中不一定有抽象方法，但抽象方法必须出现在抽象类中
6.一个非抽象的类继承抽象类，必须将抽象类中的抽象方法覆盖、实现、重写。
7.抽象类不能被final修饰 抽象方法不能被final修饰
8.抽象类中既可以有抽象方法，又可以有正常方法

public abstract class  A
{
	A()
	{
		System.out.println("A....");
	}
	
	//抽象方法
	public abstract void m1();
	
	//入口
	public static void main(String[] args)
	{
		//抽象类无法创建对象
		//A a= = new A();
		
		//多态
		A a = = new B();
	}
}


class B extends A
{
	public void m1()    //一个非抽象的类继承抽象类，必须将抽象类中的抽象方法覆盖、实现、重写。
	{
		
	}
	
	B()
	{
		super();  //父类的构造方法虽然被调用了，但是并没有创建父类对象
		Syetem.out.println("B...");
	}
}

———————————————————————————————————————————————————————————————————————
模板方法设计模式
1.在定义功能是，功能的一部分是确定的，但有一部分是不确定的，而确定的部分在使用不确定的部分
  那么这时候就要将不确定的部分暴露出去，由该类的子类去完成

abstract class GetTime
{
	public final void getTime()   //确定部分使用final修饰
	{
		long start = System.currentTimeMillis();
		runcode();
		long end = System.currentTimeMillis();
		
		System.out.println("毫秒："+ (end - start));
	}
	
	public abstract void runcode();   //不缺的部分使用abstract修饰
}

===================================================================================================================================================
接口

接口也是一种引用类型，可以等同看做类
	1.如何定义接口，语法：
		（修饰符）interface 接口名()
	2.接口中只能出现：常量、抽象方法
	3.接口其实是一个特殊的抽象类，特殊在接口是完全抽象的
	4.接口中没有构造方法，无法被实例化
	5.接口和接口中可以多继承，因为接口中没有构造方法，所以可以多继承
	  /*
			疯狂姿姿：
			如果普通方法实现了多继承，如何调用父类中的方法，如果继承太多，根本无法确定是哪一个父类
			所以单继承，可以super直接定位到父类，简单
			
			如果是接口，主要目的就是面向接口，重写接口中的方法，而不是调用接口中的方法
			接口中的方法都是抽象方法，意思就是都需要重写，所以就不需要构造方法
	  
	  */
	6.一个类可以实现多个接口（这里的实现可以等同看作继承）同样是由于接口中没有构造方法
	  
	7.一个非抽象的类实现接口，需要将接口中所有的方法 实现 重写 覆盖

public interface A
{
	//常量（必须用public static final修饰）
	public static final string SUCCESS = "success";
	public static final string double PI = 3.14;
	
	//public static final 是可以省略的
	byte MAX_VALUE = 127;  //常量
	
	//抽象方法（接口中所有的抽象方法都是public abstract）
	public abstract void m1();
	
	//public abstract 是可以省略的
	void m2();
}	

interface B 
{
	vodi m1();
}

interface C 
{
	void m2();
}

interface D 
{
	void m3();
}

interface E extends B,C,D 
{
	void m4();
}

//inplenments是实现的意思，是一个关键字
//implements和extends意义相同
class MyClass implements B,C 
{
	public void m1(){}
	public void m2(){}
}

class implements E 
{
	public void m1(){}
	public void m2(){}
	public void m3(){}
	public void m4(){}
}

_______________________________________________________________
接口作用：
	1.可以使项目分层，所有层都面向接口开发，开发效率提高了
	2.接口可以使代码和代码之间的而耦合度降低，就像内存条和主板之间的关系，变的”可插拔“
	  可随意切换
	  
	3.接口和抽象类都能完成某个功能，优先选择接口
	  因为接口可以多实现 多继承
	  并且一个类除了实现接口之外，还可以去继承其他类（保留了类的继承）

public interface CustomerService
{
	void logout();
}

public class Test
{
	public static void main(String[] args)
	{
		//要执行CustomServiceImp1中的logout方法
		
		//以下程序面向接口去调用
		CustomerService cs = new CustomerServiceImp1();
		
		//调用
		cs.logout();
	}
}


//编写接口的实现类
//该类的编写是面向接口去实现的

public class CustomerServiceImp1 implements CustomerService
{
	public void logout()
	{
		System.out.println("成功退出系统！");
	}
}

_______________________________________________________________

/*
	汽车和发动机之间的接口
	
	生产汽车的厂家面向接口生产
	生产发动机的厂家面向接口生产
	
	简述一下这道题的做题过程：
		首先需要一辆车，这个车需要一个发动机，这是有两个牌子的发动机，因为这两个发动机实现了发动机接口，所以都可以启动，而汽车要做的事情就是测试这个牌子的发动机在这个汽车上
		能不能启动
*/


public interface Engine
{
	//所有的发动机都可以启动
	void start();
}


public class HONDA implements Engine
{
	public void start()
	{
		System.out.println("HONDA启动");
	}
}

public class YAMAHA implements Engine
{
	public void start()
	{
		System.out.println("YAMAHA启动");
	}
}

public class Car
{
	Engine e;
	
	Car(Engine e)
	{
		this.e = e;
	}
	
	//汽车应该能够测试引擎
	public void test Engine()
	{
		e.start();  //面向接口调用
	}
}


public class Test
{
	public static void main(String[] args)
	{
		//生产引擎
		YAMAHA e1 = new YAMAHA();
		
		//生产汽车
		Car c = new Car(e1);
		
		//测试引擎
		c.testEngine();
		
		//换HONDA
		c.e = new HONDA();
		
		c.testEngine();
	}
}

=====================================================================================================================================================
关于object中的toString方法：
public class Test01
{
	public static void main (String[] args)
	{
		//创建一个object类型的对象
		Object o1 = new Object();
		
		//调用toString方法
		String oSter = o1.toString();
		
		System.out.println(oSter);
		
		//创建一个Person类型的对象
		Person p1 = new Person("刘德华"， 50);
		
		//调用toString方法
		String pSter = p1.toString();
		
		System.out.println(pSter);  //意思就是输出pSter的字符串形式
		                            //print方法后买你括号中如果是一个引用数据类型，会默认调用引用类型的toString方法
	}
}

class Person
{
	String name;
	int age;
	Person(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	
	//重写toString方法
	//根据项目的需求而定
	//需求规定，显示格式：Person[name = 刘德华, age = 50]
	public String toString()
	{
		reutrn "Person[name = "+name+", age = "+age+"]";
	}
}

=====================================================================================================================================================
关于object中的equals方法：
设计目的：判断两个对象是否一致
public class Test01
{
	public static void main(String[] args)
	{
		Object o1 = new Object();
		Object o2 = new Object();
		
		boolean b1 = o1.equals(o2);
		
		System.out.println(b1);  //false
		
		Star s1 = new Star(100,"黄晓明");
		Star s2 = new Star(100,"黄晓明");
		
		System.out.println(s1.equals(s2)); //true
	}
}

class Star
{
	int id;
	String name;
	
	public Star(int id, String name)
	{
		this.id = id;
		this.name = name;
	}
	
	//Object中的equals方法比较的是内存地址
	//在现实的业务逻辑中，不应该比较内存地址，应该比较内容
	//所以Object中的equals方法也要重写
	//根据需求规定重写equals方法
	//需求规定：如果身份证号一致，并且姓名也一致，则代表是同一个人
	//s1.equals(s2);
	public boolean equals(Object obj)
	{
		if (this == obj)  //两个的内存地址是一致的
			reutrn true;
		if(obj instanceof Star) //如果这个obj是Star类型
		{
			Star s = (Star)obj;  //obj是object类型，所以需要做强制类型转换
			
			if(s.id == id && s.name.equals(name))   //字符串中也有一个equals函数，哪个类型调用它，她就是啥类型里头的函数
			{
				reutrn true;
			}
		}
		return false;
	}
}


=====================================================================================================================================================
关于Object中的finalize方法  垃圾回收器

	finalize方法什么时候调用？
		1.finalize方法每个java对象都有
		2.finalize方法不需要程序员调用，由系统自动调用
		3.java对象如果没有更多的引用指向它，则该java对象称为垃圾数据
		 等待垃圾回收器的回收，垃圾回收器在回收这个java对象之前会启动调用该对象的finalize方法
		finalize方法是该对象马上就要被回收了，例如：需要释放资源，则可以在该方法中释放
		
public class Test01
{
	public static void main(String[] args)
	{
		Person p1 = new Person();
		
		p1 = null; //没有引用指向它，等待回收
		
		//程序员只能减一垃圾回收器回收垃圾
		System.gc();   //System中有gc方法是运行垃圾回收器   garbage collection
	}
}

class Person
{
	//重写object中的finalize方法，重写的目的就是为了输出那句话
	public void finalize() throws Throwable
	{
		System.out.println(this + "马上就要回收了！);
		
		//让引用再次重新指向该对象 该对象不是垃圾数据，不会被垃圾回收站回收
		//Person P = this;
	}
	
}


public class Test01
{
	public static void main(String[] args)
	{
		//hashcode方法返回的是该对象的哈希码值
		//java对象的内存地址经过哈希算法得出的int类型的数值
		
		System.out.println(t.hashCode); 
	}
}


=====================================================================================================================================================
软件包
/*
	软件包机制：
		1.为了解决类的命名冲突问题，在类名前加命名空间（包机制）
		2.在java中使用package语句定义包（单包、复包）
		3.package语句只能出现在.java源文件的第一行
		4.package定义的格式通常采用公司域名倒叙形式
		5.包就相当于儿子，你的儿子，还是我的儿子，所以必须说是在哪个包下的
		package意思是这个是哪个包    import意思是从哪里调来的包+导入的是包中的类
		建议：不要写通配符*，需要用到包中的哪个类，就导入哪个类
		
		
		
		例如：com.bjpowernode.oa.system
		
		以上包含义：bjpowerndoe公司开发oa项目，system是oa项目中其中一个模块
		
		package定义的全格式：公司域名倒叙 + 项目名 + 项目名；
		
		5.完整的类名是带有包名的
		6.带有package语句的java源文件必须这样编译：
		 javac -d 生成路径                        java源文件路径
		 
		 javac -d 你想把它放到哪里去的路径        User.java    就是原来的那个名字

		C:\Users\小可爱\Documents\MyJava\javaProject\Java-SE\chapter-03\package_import>javac -d . User.java   编译到当前路径
		C:\Users\小可爱\Documents\MyJava\javaProject\Java-SE\chapter-03\package_import>javac -d . *.java     编译当前目录下的所有java源文件
		
		7.运行
		  首先 必须cd到包含有com的目录下  之后输入 com.bjpowernode.javase.day05.User   必须写成这个形式   不可以先转到day05目录下，直接java User  
		  【com.bjpowernode.javase.day05】相当于姓   User相当于名
		  C:\Users\小可爱\Documents\MyJava\javaProject\Java-SE\chapter-01>java com.bjpowernode.javase.day05.User
		  
		8.我懂了
		  如果是javac -d c:\myclass Demo.java
		  得设置路径：classpath=c:\myclass
		  最后才java pack.JarDemo
*/

package com.bjpowernode.javase.day05;

public class User 
{
	public static void main(String[] args)
	{
		System.out.println("塔塔最爱姿姿");
	}
}


//下面这个是可以输出的，因为都在一个包内
package com.bjpowernode.javase.day05

public class Test01
{
	public static void main(String[] args)
	{
		User u = new User();
		System.out.println(u);
	}
}



package com;

//import语句可以引入其他类 import语句只能出现在package语句之下，class定义的语句之上
import com.bjpowernode.javase.day05.User;  //还有一种写法com.bjpowernode.javase.day05. *;


public class Test02
{
	public static void main(String[] args)
	{
		//classpath就是当前路径，在这个路径中没有User
		//User u = new User();
		
		//第一种方法
		com.bjpowernode.javase.day05.User u = new com.bjpowernode.javase.day05.User();
		System.out.println(u);  //输出了
		
		//第二种方法 import
		User u1 = new User();
		System.out.println(u1);
		
		//java.lang; 软件包下所有的类不需要手动导入。系统自动导入
		Object  o = new Object();
		System.out.println(o); 
		
		//日期必须导入包
		Data t = new Data();
		
		
	}
}

=====================================================================================================================================================
内部类
里面能动  外部不能动法
https://www.runoob.com/w3cnote/java-inner-class-intro.html
静态内部类
1.静态内部类可以等同看作静态变量，可以访问外部类中私有的数据
2.静态内部类可以直接访问外部类的静态数据，无法直接访问成员

public class OuterClass
{
	//静态变量
	private static String s1 = 'A';
	
	//成员变量
	private String s2 = 'B';
	
	//静态方法
	private static void m1()
	{
		System.out.println("static's m1 method excute");
	}
	
	//成员方法
	private void m2()
	{
		System.out.println("m2 method execute");
	}
	
	//静态内部类 
	//都可以用访问控制权限的修饰符修饰——public protected private 缺省 
	static class InnerClass
	{
		public static void m3()
		{
			System.out.println(s1);
			m1();
			
			//System.out.println(s2);
			//m2();
		}
		
		public void m4()
		{
			System.out.println(s1);
			m1();
			
			//System.ouy.println(s2);
			//m2();
		}
	}
	
	public static void main(String[] args)
	{
		//执行m3
		OuterClass.InnerClasss.m3();
		
		//执行m4
		InnerClass inner = new OuterClass.InnerClass();   //有一个new就是创建一个对象，所以只调用一个构造方法,静态内部类可以直接通过类名.的方式访问
		inner.m4();
	}
	
}

//调用静态内部类
OuterClass.InnerClass in = new OuterClass().new Inner();   //有两个new就是创建两个对象，所以是调用两个构造方法，外部访问必须创建对象才可以，当然要是创建外部类对象就更可以

——————————————————————————————————————————————————————————————————
之所以可以直接访问外部类中的成员，是因为内部类中持有一个外部类的引用  格式： 外部类名.this
class Outer
{
	private int x = 3;
	
	class Inner  //内部类
	{
		int x = 4;
		void function()
		{
			x = 6;
			System.out.println("inner :" + Outer.this.x);  //值是3
			x;    //值是6
			this.x;     //值是4
		}
	}
}
————————————————————————————————————————————————————————————————————
class InnerClassDemo2
{
	public static void main(String[] args)
	{
		new Outer.Inner().function();   //分开看就是 【new Outer.Inner().】.function();  //访问静态内部类的非静态成员
		Outer.Inner.function();  //访问静态内部类中的静态成员
		//注意：当静态内部类中定义了静态成员，该内部类必须是静态的
		//当外部类中的静态方法访问内部类时内部类也必须是static的
		
		//当描述事物时，事物的内部还有事物，该事务用内部类来描述，因为内部事物再使用内部事物中的内容
	}
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
成员内部类
要动里面就动   要动里面不可能静
根基不稳，地动山摇，人在房子里跳舞没事
1.成员内部类可以等同看作成员变量
2.成员内部类中不能有静态声明
3.成员内部类可以访问外部所有的数据


public class OuterClass
{
	//静态变量
	private static String s1 = 'A';
	
	//成员变量
	private String s2 = 'B';
	
	//静态方法
	private static void m1()
	{
		System.out.println("static's m1 method excute");
	}
	
	//成员方法
	private void m2()
	{
		System.out.println("m2 method execute");
	}
	
	//成员内部类 
	//都可以用访问控制权限的修饰符修饰——public protected private 缺省 
	class InnerClass
	{
		//静态方法 
		//public static void m3() {}
		public void m4()
		{
			System.out.println(s1);
			m1();
			
			System.ouy.println(s2);
			m2();
		}
	}
	
	public static void main(String[] args)
	{

		//创建外部类对象
		OuterClass oc = new OuterClass();
		
		InnerClass inner = oc.new InnerClass();
		
		inner.m4();
	}
	
}

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
【局部内部类】
1.局部内部类等同于局部变量
2.重点：局部内部类在访问局部变量的时候，局部变量必须使用final修饰
public class OuterClass
{
	public voic m1()
	{
		//局部变量
		final int i = 10;
		
		//局部内部类 
		//局部内部类不能用访问控制权限修饰符修饰
		class InnerClass
		{
			//内部类不能有静态声明
			//public static void m1()
			//{}
			
			//成员方法
			public void m1()
			{
				System.out.println(i);
			}
		}
		
		———————————————————————————————————————————————————————————————————————
		//为什么必须采用final修饰
		i = 100;
		
		执行m1方法-->10  //本来应该输出100的，可是执行有先后顺序，输出的就是10
		———————————————————————————————————————————————————————————————————————
		
		//调用m2
		InnerClass inner = new InnerClass();
		inner.m2();
	}
	
	//入口
	public static void main(String[] args)
	{
		OuterClass oc = new OuterClass();
		oc.m1();
	}
}

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
【匿名内部类】
1.指的是类没有名字
2.定义匿名内部类的前提：内部类必须继承一个类或者实现接口
3.匿名内部类的格式： new 父类或者接口(){定义子类的内容}
4.其实匿名内部类就是一个匿名子类对象，而且这个对象有点胖，可以理解为带内容的对象
5.匿名内部类中定义的方法最好不要超过3个
  
interface Inter
{
	void method();
}
 
class Test
{
	//补是代码，通过匿名内部类
	/*
	static class Inner implements Inter
	{
		public void method()
		{
			System.out.println("method run");
		}
	}
	*/
	static Inter function()
	{
		return new Inter()
		{
			public void method()
			{
				System.out.println("method run");
			}
		};
	}
}
  
class InnerClassTest
{
	public static void main(String[] args)
	{
		//Test.function(); Test类中有一个静态的方法function
		//.method():function这个方法运算后的结果是一个对象，而且是一个Inter类型的对象
		//因为只有Inter类型的对象，才可以调用method方法
		Test.function().method();
	}
}
————————————————————————————————————————————————————————————————————————————————————————————
public class Test
{
	public static void t(CustomerService cs)
	{
		cs.logout();
	}
	
	public static void main(String[] args)
	{
		//调用t方法
		t(new CustomerServiceImp1());
		//第二种调用t方法
		//使用匿名内部类的方式执行t方法
		//整个这个”new CustomerService() {}“就是个匿名内部类
		
		t(new CustomerService()
		{
			public void logout()
			{
				System.out.println("系统已安全退出！");
			}
		}
		);
		
	}
	
}

//接口
interface CustomerService
{
	//退出系统
	void logout();
}

//编写一个类实现CustomerService接口
class CustomerServiceImp1 implements CustomerService
{
	public void logout()
	{
		System.out.println("系统已经安全退出！");
	}
}

================================================================================================================================================================================
泛化关系：就是继承关系 接口和接口之间的继承 类和类之间的继承关系
实现关系：类对接口的实现
并联关系：类与类之间的连接，一个类可以知道另一个类的属性和方法，在java语言中使用实例变量体现
		  在当前类中含有其他类的引用，在当前对象中含有其他对象的引用
		  例如：你和你朋友
聚合关系：是并联关系的一种，是较强的并联关系，是整体和部分的关系，如：汽车和轮胎，它与关联关系不同，并联关系的类处在同一个层次上
          ，而聚合关系的类处在不同的层次上，一个代表整体，一个代表部分，在java语言中使用实例变量体现
合成关系：是关系的一种，比聚合关系强的关联关系，如：人和四肢，整体对象决定部分对象的生命周期，部分对象每一时刻只与一个对象发生合成关系，在java语言中使用实例变量体现
依赖关系：局部变量，形参

//ClassRoom就是整体
public class ClassRoom
{
	//ClassRoom和List集合属于并联关系，在同一个层级上
	//ClassRoom和Student属于聚合关系，一个是整体，一个是部分
	List<Student> stus;  //student就是部分
	
	//绝活关系：整体不依赖部分，部分也不会依赖整体
	//整体无法决定部分的生命周期
}

public class 人
{
	//人和List是并联关系
	//人和四肢是合成关系，人是整体，四肢是部分
	//合成关系和聚合关系是相似的，区别的地方在：整体和部分是紧密相连的 整体的生命周期决定部分的生命周期
	List<四肢> s;
}


================================================================================================================================================================================
is-a    类和类之间的继承关系
is-like-a 类去实现接口
has-a  A中有一个B
public class A 
{
	private B b;
}

================================================================================================================================================================================
异常
try
{
	可能出错的代码;
}
catch(ArithmeticException e)
{
	System.out.println(",,,");   //你想对这个出错代码的处理
}
————————————————————————————————————————————————————————————————

在try中的代码，系统认为可能不成功
public class Test
{
	public static void main(String[] args)
	{
		int m;
		try
		{
			m = 2;
			System.out.printf("1");
		}
		System.printf("%d", m);  //会报错
	}
}

————————————————————————————————————————————————————————————————
如何从键盘上输入一个数，并接受
这个例子说明了，无法使用if else
本程序出现的问题是无法通过逻辑判断来解决的，Java提供的异常处理机制可以很好的解决这个问题
public class Test
{
	public static void main(String[] args)
	{
		int i;
		Scanner sc = new Scanner(System.in);
		
		try
		{
			//java.util.random.nextInt  
			/*
				你这个代码不全吧
				之前应该有一个 java.util.Scanner sc=new java.util.Scanner(System.in);

				其中
				int n=sc.nextInt()的意思就是 获取键盘的输入：
				如果执行到了这一行，那么程序会暂停，等待你在控制台输入，然后把输入的整数值赋给整形变量 n
			
			*/
			
			i = sc.nextInt();
			System.out.printf("i = %d\n", i);
		}
		catch(InputMismatchException e)
		{
			System.out.printf("输入的数字不合法，程序被终止\n");
		}
		
	}
}

————————————————————————————————————————————————————————————————
1.异常的基本概念：在程序运行过程中出现的错误，成为异常   
                  第一：异常模拟的是现实世界中不正常的事件
				  第二：java中采用类去模拟异常
				  第三：类是可以创建对象的
					NullPointerException e = 0x1234;
					e是引用类型，e中保存的内存地址指向堆中的对象
					这个对象一定是NullPointerException类型
					这个对象就表示真实存在的异常事件
					NullPointerException是一类异常
					
					抢劫就是一类异常   ————————————>类
					张三被抢劫就是一个以产生事件  ——————————————>对象
	异常机制的作用：
		java语言为我们提供一种完善的额异常处理机制
		作用是：程序发生异常事件之后，为我们输出详细的信息，程序员通过这个信息，可以对程序进行一些处理，使程序更加健壮
		
	异常的好处：
		1.将问题进行封装
		2.将正常流程代码和问题处理代码相分离，方便于阅读
		
public class NullPointerException
{
	public void main(String[] args)
	{
		int a = 10;
		int b = 0;
		int c = a / b;
		
		//上面的代码出现了异常没有处理，下面的代码不会执行，直接退出了JVM
		System.out.println("Hello WOrld);
	}
}
                  
/*
	以上程序编译通过了，但是运行时出现了异常，表示发生某个异常事件
	JVM向控制台输出如下的信息
	本质，程序执行过程中发生了算数异常这个事件，JVM为我们创建了一个ArithmeticException类型的对象
	并且这个对象中包含了这个异常的详细信息，并且JVM将这个对象中的信息输出到控制台
*/

2.异常的分类
                                            Object
											   |
										   Throwable【所有的异常都是可抛出的】
							    	/                         \
								Errow                      Exception【Exception时可以处理的，如果没有异常处理，则程序直接退出JVM】
								                       /                \
【所有Exception的直接子类都是编译时异常】 ——      编译时异常     RunTimeException【运行时异常】所有RunTimeException的子类都是运行时异常，运行时异常程序员在编写阶段不需要对他进行处理
													   |
						【所有的编译时异常，要求程序员在编写程序阶段，必须对他进行吹了，如果不处理的话，编译无法通过，处理异常有两种方式，捕捉和声明抛出
						  捕捉：try...catch..,声明抛出就是在方法声明的而位置上使用throws关键字抛出异常】

编译时异常：发生的机率比较高
运行时异常：发生的机率比较低


3.异常的捕获和处理
/*
	异常处理有两种方式
		1.声明抛出 throws    throws表示这个方法对于抛出的IOException这个异常不进行处理，我交给被调用者处理（上一步是哪个方法调用它的，或者是main函数
		                     调用它的，交给这个方法来处理，到达最高总司令之后就抛给了Java虚拟机，抛给他，也可以自己写try..catch）
		  public void f() throws IOException
		  {
			  throws new IOException();   //这里并没有对这个异常进行处理
		  }
		2.捕捉 try...catch...
		  建议在进行catch处理时，catch中一定要定义具体的处理方法
		  不要简单定义一句e.printStackTrace()
		  也不要简单的就书写一条输出语句
		  所以说具体到什么异常比较好，不要单纯写Exception，可以在catch中加上你想告诉用户的
	以下程序演示第一种方式：声明抛出，在方法声明的位置上使用throws关键字向上抛出异常
*/

java.lang.Object->java.lang.Throwable->java.lang.Exception->java.io.IOException->java.io.FileNotFoundException
import java.io.*;

public class ExceptionTest03
{
	//public static void main(String[] args) throws FilmNotFoundException
	//public static void main(String[] args) throws IOException
	public static void main(String[] args) throws Exception
	{
		//创建文件输入流，读取文件
		//思考：java编译器时如何知道以下的代码执行过程中可能出现异常
		//java编译器时如何知道这个异常发生的机率比较高呢
		//java编译器不是那么智能，因为FileInputStream这个狗奥方法在声明的位置上使用了throws FilmNotFoundException;
		FileInputStream fis = new FileInputStream("c:/ab.txt");
		//public FileInputStream(String name) 
		                    throw FileNotFoundException  //这句话的意思就是如果出现的问题，往FileNotFoundException抛过去
	}
}


—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
	深入throws
*/
public class ExceptionTest04
{
	public static void main(String[] args) throws FilmFoundException
	{
		m1();	
		//使用throws处理异常并不是真正的处理异常，而是推卸责任
		//谁调用的就会抛给谁
		//上面的m1方法如果出现了异常，因为采用的是上抛，给了 JVM，JVM遇到这个异常就会退出JVM，下面的而代码不会执行
		SYstem.out.println("Hello World");
		
		//第二种方法是使用try catch
		try
		{
			m1();
		}
		catch(FileNotFoundException e)
		{
			SYstem.out.println("Hello World");  //这里这条语句就可以执行
		}
	}
	
	public static void m1 throws FilmFoundException()
	{
		m2();
	}
	
	public static void m2 throws FilmFoundException()
	{
		m3();
	}
	
	public static void m3 throws FilmFoundException()
	{
		new FilmInputStream("c:/ab.txt");  //FilmInputStream构造方法声明位置上使用了throws（向上抛）
	}
}

//在程序运行过程中发生了FilmNotFoundException类型的异常
//JVM为我们创建了一个FilmNotFoundException类型的对象
//该对象携带以下信息
//JVM负责将该对象的星系打印到控制台
//比你且JVM停掉了程序的运行

—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


/*
	处理异常的第二种方式，捕捉..try..catch..
	
		语法：
			try
			{
				可能出现异常的代码；
			}
			catch（异常类型1 变量）
			{
				处理异常的代码；
			}
			catch（异常类型2 变量）
			{
				处理异常的代码；
			}...
	
	1.catch语句块可以写多个
	2.但是从上到下catch，必须从小类型异常到大类型异常进行捕捉。
	3.try..catch...中最多执行一个语句块，执行结束之后try...catch...就结束了
*/

import java.io.*;
public class ExceptionText05
{
	public static void main(String[] args)
	{
		//以下代码无法通过，因为FilmNotFoundException没有处理
		/*
			try
			{
				//FilmFoundException
				FilmInputStream fis = new FileInputStream("c:/ab.txt");
			}
			
			catch(ArithmeticException e)   //捕获的是算数异常
			{
				
			}
		
		*/
		
		/*
		try
		{
			//以下程序编译无法通过
			//因为还有更多的IOException没有处理，只有在下面加上catch(IOException e)才可以
			FilmInputStream fis = new FileInputStream("c:/ab.txt");
			
			
			//public int read()
				//throws IOException
			
			fis.read();
		}
		catch(FilmFoundException e)  
		{
			
		}
		catch(IOException e)
		{
			
		}
		*/
		
		/*
		//编译通过，上面的比较精确
		try
		{
			FilmInputStream fis = new FileInputStream("c:/ab.txt");
			
			
			fis.read();
		}
		catch(IOException e)
		{
			
		}
		
		*/
		
		
		/*
		//编译无法通过
		//catch可以写多个，但是必须从上到下，从小到大捕捉
		try
		{
			FilmInputStream fis = new FileInputStream("c:/ab.txt");
			
			fis.read();
		}
		catch(IOException e)  
		{
			
		}
		catch(FilmFoundException e)  //在IOException已经捕捉到异常了，重复捕捉，报错
		{
			
		}
		*/
		
		//中间可以用,隔开
		还有一种写法是public static void main (String[] args) throws FilmFoundException, IOException{}
		
		
		
		public static void main(String[] args)
		{
			try
			{
				//程序执行到此处发生了FilmFoundException类型的异常
				//JVM会自动创建一个FilmFoundException类型的对象，将该对象的地址赋给catch语句块中的e变量
				FilmInputStream fis = new FileInputStream("c:/ab.txt");
				
				//上面的代码出现了异常，try语句块的代码不再继续执行，直接进入catch语句块中执行
				System.out.println("TTTTT");
				fis.read();
			}
			catch(FilmFoundException e)  //e内存地址指向队中的那个对象时”FileNotFoundException“类型的事件
			{
				System.out.println("读取的文件不存在");
			}
			catch(IOException e)
			{
				System.out.println("其他IO异常");
			}
		}
		
	}
}


4.关于getMessage和printStackTrace（print的意思就是打印，意思就是写这个可以打印出错误的相关信息）方法的应用

import java.io.*;
public class ExceptionTest07
{
	public static void main(String[] args)
	{
		/*
		try
		{
			FilmInputStream fis = new FileInputStream("c:/abc.txt");
		}
		catch(FilmFoundException e)
		{
			//打印异常堆栈信息
			//一般情况下都会使用该方式去调试程序
			e.printStackTrace();
		}
		*/
		
		String msg = e.getMessage();
		System.out.println(msg);  //显示出的错误提示信息没有上面详细就是printStackTrace
	}
	
	//这段代码会执行
	System.out.println("ABC");
}


 
5.关于finally语句块
	finally语句块可以直接和try语句块连用。  try...finally...
	try...catch...finally 也可以 
	在finally语句块中的代码是一定会执行的

import java.io.*;
public class ExceptionTest08
{
	public static void main(String[] args)
	{
		
		//先执行ABC 再执行Test  最后执行return
		try
		{
			System.out.println("ABC");
			return ;
		}
		finally
		{
			System.out.println("Test");
		}
		
		————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
		
		try
		{
			FileInputStream fis = new FilmInputStream("Test.java");   //当前面public static void main(String[] args) throws Exception
			
			//不会执行
			System.out.println("TTTT");
		}
		finally
		{
			//会执行
			System.out.println("AAAA");
		}
		
		————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
		
		//只要子啊finally语句块之前退出了JVM，则finally语句块不会执行
		try
		{
			System.exit(0);   //非零状态码表示异常终止。
		}
		finally
		{
			System.out.println("finally...");
		}
		————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
	}
}

深入finally语句块
public class ExceptionTest09
{
	public static void main(String[] args)
	{
		int i = n1();
		System.out.println(i);  //10  不是   11
	}
	
	public static int m1()
	{
		try
		{
			int i = 10;
			return i;
		}
		finally
		{
			i++;
		}
		
		/*
		以上代码的执行原理
		int i = 10;
		try
		{
			
			int temp = i;
			return temp;    //这里就直接return了，我觉得是因为分块的原因，两个代码块中并无关联
		}
		finally
		{
			i++;
		}
		*/
	}
	
}

//finally语句块是一定会执行的，所以通常在程序中为了保证某一资源一定会释放，所以一般要在finally语句块中释放
//IO异常
public class ExceptionTest10
{
	public static void main(String[] arg)
	{
		//如果try代码块内部，就是表示只在try代码块内部有作用，下面finally语句块就不能用fis了
		FilmInputStream fis = null;
		
		try
		{
			fis = new FilmInputStream("ExceptionTest1.java");
		}
		catch(FileNotFountException e)
		{
			e.printStackTrace();
		}
		finally
		{
			//如果上面的文件路径例如c://java  不存在，就会出现空指针，空指针不能调用close，否则就会出现空指针异常
			//关闭的时候，关闭的也是文件，会和操作系统内部产生关联，会出现IO异常
			//为了保证资源一定会释放
			if(fis != null)
			{
				//public void close()
				//		throw IOException
				try
				{
					fis.close();
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		}
	}
}


***********
final finalize finally 的区别
final        可以用来修饰成员变量无法被改变，修饰类（无法被继承），修饰方法（无法被覆盖），修饰的成员变量需要手动赋值
finalize     是object中一个方法的名字，垃圾回收器在回收java对象之前会先自动调用java对象的finalize方法
finally      异常处理机制中的finally语句块


6.如何手动向上抛出异常——自定义异常
/*
	1.RuntimeException特别特殊，不用throws，编译一样通过   如果在函数上申明了该异常，调用者可以不用进行处理
	  之所以不用再函数上申明，是因为不需要让调用者处理，当该异常发生，希望该程序停止，因为在运行时，出现了无法继续运算的情况，希望程序停止后
	  对代码进行修正，
	  
	  自定义异常时：如果该异常的发生，无法继续进行运算，就让自定义异常继承RuntimeException
	2.throw和return都是程序结束标识，所以throw下不可以有语句*
	
	自定义无效名字异常
		1.编译时异常，直接继承Exception
		2.运行时异常，直接继承RuntimeException
	因为项目中会出现一些特有的问题，这些并未被java描述并分装对象
	
	如果说除数小于0，java虚拟机会自动识别，建立一个对象，抛给catch
	如果说自定义异常，就得自己建立对象
	
	如果说最终异常抛给java虚拟机，虚拟机就会自动调用printStackTrace，打印错误信息，并终止程序
	
	toString() 打印的是异常名称和信息
	
	如果是自定义的异常，不具有可抛性，必须继承Throwable或Exception或Error
	
	throws使用在函数上  throw使用在函数内
	/*
		class Person
		{
			
		}
		class Demo
		{
			int div(int a, int b) throws Person
		}
	
	*/

*/

/*
	推理一下，既然父类接收并打印出异常信息，所以父类中肯定有接受信息和打印信息的功能，只要把信息传给父类就好super
	就可以直接通过getMessage获取自定义的异常信息
	
	class Throwable
	{
		private String message;
		Throwable(String message)
		{
			this.message = message;
		}
		
		public String getMessage()
		{
			return message;
		}
	}
	
	class Exception extends Throwable
	{
		Exception(String message)
		{
			super(message);
		}
	}

	——————————————
	class FuShuException exception Exception
	{
		private int value;
		FuShuException()
		{
			super();
		}
		
		FuShuException(String msg, int value)
		{
			super(msg);
			this.value = value;
		}
		
		public int getValue()
		{
			return value;
		}
	}
	
	catch 
	{
		System.out.println(e.toString());  //调用的是父类的toString
		System.out.println("错误的负数是：" + e.getValue());   //将这个错误的值输出
	}
*/
public class IllegalNameException extends Exception   //编译时异常
public class IllegalNameException extends RunTimeException    //运行时异常
//如果继承的时运行时异常，不用throws，不用try  catch，直接new对象throw就好0
{
	//定义一般一般提供两个构造方法
	
	//如果没有异常处理信息
	public IllegalNameException()
	{
		
	}
	
	//如果有异常处理信息
	public IllegalNameException(String mgs)
	{
		super(msg);   //调用Exception的有参构造方法
	}
}

//顾客相关的业务
public class CustomerService
{
	public void register(String name) throws IllegalNameException   //把你想说的抛给调用者
	{
		//完成注册
		if(name.length() < 6)
		{
			//异常
			//创建异常对象
			//IllegalNameException e = new IllegalAccessException("用户名长度不能少于6位");
			
			//手动抛出异常
			//throw e;
			throw new IllegalNameException("用户名长度不能少于6位");    //其实这个的意思就是如果出现这个问题，你想让虚拟机说点啥
		}
		
		//如果代码能执行到此处，证明用户名是合法的
		System.out.println("注册成功！");
	}
}

//模拟注册
public class Test
{
	public static void main(String[] args)
	{
		String username = "jack";
		
		//注册
		CustomerService cs = new CustomerService();
		
		try
		{
			cs.register(username);
		}
		catch(IllegalNameException e)
		{
			System.out.println(e.getMessage);  //调用父类的getMessage方法，将用户名长度不能少于6位输出
		}
	}
}
——————————————————————————————————————————————————————————————————————————————————

郝斌
import java.io.*;
class DivisorIsZeroException extends Exception
{
	public DivisorIsZeroException(String name)
	{
		super(name);
	}
}

class A
{
	public int divide(int a, int b) throws DivisorIsZeroException
	{
		int m = 0;
		
		if(0 == b)
			throw new DivisorIsZeroException("除数不能为0");   //如果0 == b  照之前的想法，你肯定想说些什么，现在就是把你想说的话包装成一个对象
		else
			m = a / b;
			
		return m;
	}
}

——————————————————————————————————————————————————————————————————————————————————

/*
	重写的方法不能比被重写的方法抛出更宽泛的异常
*/

import java.io.*;
class A
{
	public void m1()
	{
		
	}
}

class B extends A
{
	//子类永远无法抛出比父类更多的异常
	public void m1() throws Exception()
}

———————————————————————————————————————

class A
{
	public void m1() throws FileNotFoundException{}
}

class B extends A
{
	public void m1() throws IOException{}
}

————————————————————————————————————————————————————————————

老师上课

//自定义异常
class LanPingException extends Exception
{
	LanPingException(String message)
	{
		super(message);
	}
}

class MaoYanException extends Exception
{
	MaoYanException(String message)
	{
		super(message);
	}
}

class NoPlanException extends Exception
{
	NoPlanException(String msg)
	{
		super(msg);
	}
}

class Computer
{
	private int state = 3;
	
	public void run() throws LanPingException, MaoYanException
	{
		//电脑可能出现的异常，并抛出异常，要抛出异常，必须知道抛给谁，所以得throws
		if(state == 2)
			throw new LanPingException("蓝屏了");
		if(state == 3)
			throw new MaoYanException("冒烟了");
		System.out.println("电脑运行");
	}
	
	public void reset()
	{
		state = 1;
		System.out.println("电脑重启");
	}
}

class Teacher
{
	private String name;
	private Computer cmpt;
	
	Teacher(String name)
	{
		this.name = name;
		cmpt = new Computer();
	}
	
	public void prelect() throws NoPlanException  //这个老师抛出计划完不成异常
	{
		
		//try catch是和别人有关，throws和 throw是和自己有关
		//catch是捕获到异常，你咋办，可以打印信息，也可以说点啥
		
		try  //因为刚才得知，电脑可能出现异常
		{
			cmpt.run();
		}
		catch(LanPingException e)  //如果蓝屏
		{
			cmpt.reset();   //电脑重启
		}
		catch(MapYanException e)   
		{
			test();
			throw new NoPlanException("课时无法继续" + e.getMessage());
		}
		
		System.out.println("讲课");
	}
	
	public void test()
	{
		System.out.printn("练习");
	}
}

class ExceptionTest 
{
	public static void main(String[] args)
	{
		Teacher t = new Teacher("毕老师");
		try
		{
			t.prelect();
		}
		catch(NoPlanException e)
		{
			System.out.println(e.toString());
			System.out.println("换老师或者放假");
		}
	}
}

——————————————————————————————————————————————————————
class Demo
{
	public static void main(String[] args)
	{
		try
		{
			showExce();   //这个是可能错误，所以下面可以写语句
			throw new Exception();   //下面不能写语句，这个是一定错误，就像break return都是这样
			
			System.out.println("A");
		}
	}
}
============================================================================================================================================
数组
1.数组是一种引用类型
2.数组是一种简单的数据结构，线性的结构
3.数组是一个容器，可以用来储存其他元素
4.数组可以储存任意一种任意数据类型元素
5.数组分类：一维数组 二维数组 三维数组 多维数组
6.数组中储存元素的类型是统一的
7.数组长度不可改变 数组拿首元素的内存地址作为数组对象的内存地址
8.数组的长度 a1.length

int[] a1 = {1,2,3};    //{1，2，3}是在堆中分配的  a1是在栈中分配的
int a2[] = {1,2,3};  //这样也可以

//动态声明一个int类型的数组，最多可以储存4个元素
//动态初始化一维数组，会现在堆内存中分配这个数组，并且数组中每一个元素都采用默认值 byte,short,int ,long,float
int[] a1 = new int[4];   //我感觉就类似于int *a1 = (int *)malloc(sizeof(int) * 4);  数组中储存的每一个数字都是0


如果是引用类型的数组
Object[] objs = new Object[3];
Object c = objs[index];
o.toString();   //注意空指针异常。因为引用类型的数组默认值是null
System.out.println(o);  //可以输出 null  null null  因为println有一个机制如果是null，输出null，如果不是null，输出这个字符串

public class ArrayText05
{
	public static void main(String[] args)
	{
		Animal[] as = new Animal[4];
		
		Dog d1 = new Dog();
		Dog d2 = new Dog();
	    Cat c1 = new Cat();
		Cat c2 = new Cat();
		
		as[0] = d1;
		as[1] = d2;
		as[2] = c1;
		as[3] = c2;
		
		for(int i = 0; i < as.length; i++)
		{
			Animal a = as[i];
			
			if(a instanceof Cat)
			{
				Cat c = (Cat)a;
				c.move();
			}
			
			else if(a instanceof Dog)
			{
				Dog d = (Dog)a;
				d.eat();
			}
		}
	}
}


class Animal
{
	
}

class Dog extends Animal
{
	public void eat()
	{
		System.out.println("Dog eat");
	}
}

class Cat extends Animal
{
	public void move()
	{
		System.out.println("Cat move");
	}
	
}

__________________________________________________________________
往函数中传一个数组
int[] a = {1,2,3,4};
m1(a);
m1(new int[] {1,2,3,4});
——————————————————————————————————————————————————————————————————
String[] args是专门用来接收命令行参数的
例如：java ArrayTest07 abc def aaa     如果输出的是args.length  输出的结果是3  
JVM在调用ArrTest07类的main方法之前，先 abc def aaa 字符串以空格的方式分割，然后存在string数组中
main方法中的string[]数组的涉及主要是用来接收命令行参数的

//需求说明，运行该软件是必须提供用户名和密码
//格式：java ArrayTest07 username password
//如果用户名没有提供足够的参数，则退出系统

if(args.length != 2)
{
	System.out.println("要想使用系统，必须这样输入：java ArrayTest07 username password");
	return;
}

String username = args[0];
String password = args[1];

//java中比较字符串是否相等，必须使用equals方法
//String类型是SUN提供，已经equals重写了，比较的是内容
if("admin".equals(usernaem) && "123".equals(password))  //把admin写前面，可以避免空指针异常
{
	System.out.println("成功");
}
else
{
	System.out.println("失败");
}


——————————————————————————————————————————————————————————————————————————————————————————————
关于数组的拷贝
System.ayyaycopy(原数组，原数组的开始下表，目标数组，目标数组的开始下标，拷贝的长度);

=====================================================================================================================================================
二维数组
静态初始化二维数组
int[][] a = {
				{1,2,3},
				{45,34},
				{0}
			};
			
以上这个数组有多少个一维数组
System.out.println(a.length);

获取最后一个一维数组中的最后一个元素
System.out.println(a[a.length - 1][a[a.length - 1].length - 1]);
		
for(int i = 0; i < a.length; i++)
{
	for(int j = 0; j < a[i].length; i++)
	{
		System.out.println(a[i][j]);
	}
}

关于二维数组的动态初始化
int[][] a = new int[3][4];

往函数中输入
m1(new int [][]{{1,23,4} ,{2, 4}, {7, 8, 9}});


//如何接受用户的键盘输入
import java.util.Scanner;

public class KeyInput
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);  //从标准输入流中读取
		
		//程序执行到此处，停下来，等待用户的输入
		String userInput = s.next();
		System.out.println(userInput);
	}
}

=====================================================================================================================================================
使用数组模拟栈

public class StackOperationException extends Exception
{
	public StackOperationException(){}
	public staticOperationException(String msg)
	{
		super(msg);
	}
}


//栈，先进后出
public class stack
{
	//使用数组储存数据
	//栈可以储存多个引用类型的元素
	Object[] elements;
	
	//指向栈顶元素上方的一个帧
	int index;
	
	//这两个构造方法是控制栈的大小
	Stack()
	{
		this(5);
	}
	
	Stack(int max)
	{
		elements = new Object[max];
	}
	
	//栈应该对外提供一个压栈的方法
	public void push(Object element) throws StackOperationException
	{
		if(index == elements.length)
		{
			throw new StackOperationException("栈已满");
		}
		
		elements[index++] = element;
	}
	
	//栈应该对外提供一个弹栈的方法
	public Object pop() throws StackOperationException
	{
		if(index == 0)
		{
			throw new StackOperationException("栈已空！");
		}
		return elements[--index];
	}
}

public class Test
{
	public static void main(String[] args)
	{
		//这里只是初始化一些东西，不会出现异常
		Stack s = new Stack();
		User u1 = new User("JACK", 20);
		User u1 = new User("SMITH", 21);
		User u1 = new User("FORD", 22);
		User u1 = new User("KING", 23);
		User u1 = new User("COOK", 24);
	}
	
	try
	{
		s.push(u1);
		s.push(u2);
		s.push(u3);
		s.push(u4);
		s.push(u5);
		
		s.push(u5);
	}
	catch(StackOperationException e)
	{
		e.printStackTrace();
	}
	
	try
	{
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		
		System.out.println(s.pop());
	}
	catch(StackOperationException e)
	{
		e.printStackTrace();
	}
}

class User
{
	String name;
	int age;
	
	User(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
}

====================================================================================================================================================
Array
Array是SUN提供的一个工具类，该工具类主要针对的是数组的操作：排序、二分查找

import java.util.Array;
public class ArraysTest
{
	public static void main(String[] args)
	{
		int[] a = {3,1,6,2,5};
		
		//排序
		Array.sort(a);
		
		//输出
		for(int i = 0; i < a.length; i++)
		{
			System.out.println(a[i]);
		}
		
		//堆排序之后的数据进行二分查找
		int index = Array.binarySearch(a,1);
		Syatem.out.println(index);
		
	}
}


====================================================================================================================================================
String类 
1.String类是不可变类，也就是说String对象声明后，将不不可修改
字符串不变; 它们的值在创建后不能被更改。 字符串缓冲区支持可变字符串。 因为String对象是不可变的，它们可以被共享。 例如： 

     String str = "abc";
 相当于： 

     char data[] = {'a', 'b', 'c'};
     String str = new String(data);
_____________________
String s1 = "abc";
s1 = "def";  //可以让s1重新指向，s1之前没有final，所以s1可以重新指向，是“abc”字符串本身不可变
—————————————————————

2.提升字符串的访问效率，在软件中使用了“缓存”技术，所以在java中所有使用双引号括起来的字符串都会在字符串常量池中创建一份，字符串常量在方法区中被存储

3.在程序执行过程中，如果程序用到了某个字符串，那么程序会在字符串常量池中去搜多该字符串，如果没有找到，则在字符串常量池中新建一个“abc”字符串，如果找到
直接拿来用，字符串常量池是一个缓冲区，为了提高访问字符串的效率
String s2 = "Hello";
String s3 = "Hello";

System.out.println(s2 == s3);  //true

//比较两个字符串是否相等，不能用“ == ”
String s4 = new String("abc");
String s5 = new String("abc");
System.out.println(s4 == s5);   //false

//比较两个字符串是否相等，必须使用String类提供的equals方法 objects中的equals是比较地址，而String重写了equals方法
System.out.println(s4.equals(s5));  //true


//以下程序结束之后，会在字符串常量池中创建3个字符串对象
//使用String的时候我们因该尽量不要做字符串频繁的拼接操作，因为字符串一旦创建不可改变，只要频繁拼接，就会在字符串常量池中创建大量的字符串对象
//给垃圾回收带来问题
//"aaa" "bbb" "aaabbb"
String s6 = "aaa";
String s7 = "bbb";
String s8 = s6 + s7;


//分析以下程序创建字符串对象的区别

//在字符串常量池中创建一个“abc”，之后使栈中的s1指向字符串常量池中的“abc”
String s1 = "abc";  //创建了一个对象
//首先去字符串常量池中去搜索有没有“abc”这个字符串，如果没有，创建一个，之后再在堆中创建一个String类型的“abc”对象，再在栈中创建s2，使s2指向
//堆中的String类型对象
String s2 = new String("abc");   //创建了2个对象，浪费空间


4.关于字符串常用构造方法
String s1 = "abc";
String s2 = new String("abc");

byte[] bytes = {97,98,99,100};
String s3 = new String(bytes);
System.out.println(s3);  //abcd   String已经重写了object中的toString方法  输出他对应的字节码值

String s4 = new String(bytes, 0, 2);  //从bytes下标为0的位置开始，输出两个值
System.out.println(s4);  //ab

char[] c1 = {'我', '是', '中', '国' ,'人'};
String s5 = new String(c1);
System.out.println(s5); //我是中国人

String s6 = new String(c1,2,2);
System.out.println(s6);   //中国

5.字符串中常用的方法
//char charAt(int index);
String s1 = "塔塔是好人";
char c1 = s1.charAt(2);  //是

//boolean endWith(String endSter)
System.out.println("HelloWorld.java".endWith("java")); //true

//boolean equalsIgnoreCase(String anotherString)
System.out.println("abc".equalsIgnoreCase("ABC"));   //忽略大小写，判断两个字符串是否相等

//byte[] getBytes();
byte[] bytes = "abc".getBytes();  //97 98 99

//int indexOf(String str);   第一次出现位置的下标  "...".indexof(..);

//int indexof(String str, int fromIndex);  //从fromIndex开始寻找第一次出现的下标
"...".index("...",...);

//String replaceAll(String s1, String s2);
"....".replaceAll("java","jih");  //把这个字符串里的java全换成jih  这个程序是四个字符串

6.正则表达式
正则表达式是一门独立的学科，正则表达式是一种字符模型，专门做字符串匹配的，正则表达式是通用的

例如：正则表达式"^a{2}$"表示两个a字符，等同于aa
"ab".matches("^a{2}$")   ab和aa匹配不上  返回false
\d 数字
\D 非数字
\w 英文字母
\W 非英文字母

例：
String s1 = "ihfuicm84u8u8r384ngdcni93330co40ci59vum58c764x38nx";

//将dd替换为中
System.out.println("dd", "中");

//将dd替换为中
System.out.println(s1.replaceAll("d{2}", "中"));

//将数字替换为中
System.out.println(s1.replaceAll("\\d","中"));

//将非数字替换为中
System.out.println(s1.replaceAll("\\D", "中"));



7.StringBuffer和StringBuilder
java.lang.StringBuffer
java.lang,StringBuilder

1.StringBuffer和StringBuilder是什么？
  是一个字符串缓冲区

2.工作原理
  预先在内存中申请一块空间，以容纳字符序列，如果预留的空间不够用，则进行自动扩容，以容纳更多的字符序列

3.StringBuffer和StringBuilder和String最大的区别
  String是不可变的字符序列，储存在字符串常量池中
  StringBuffer底层是一个char数组，但是该char数组是可变的，并且可以自动扩容

4.StringBuffer和StringBuilder的默认初始化容量是16

5.如何优化StringBuffer和StringBuilder
  最好在创建StringBuffer之前，预测StringBuffer的储存字符数量，然后在创建StringBuffer的时候采用指定初始化容量的方式创建StringBuffer
  为了减少底层数组的拷贝，提高效率
  
//创建字符串缓冲区对象
StringBuffer sb = new StringBuffer();  //16

String[] ins = {"体育","音乐","睡觉","美食"};

//推荐字符串频繁拼接使用StringBuffer或者StringBuilder
for(int i = 0; i < ins.length; i++)
{
	if(i == ins.length - 1)
	{
		sb.append(ins[i]);
	}
	else
	{
		sb.append(ins[i]);
		sb.append(",");
	}	
}

System.out.println(sb);

————————————————————————————————————————————————————————————————
StringBuffer和StringBuilder的区别
StringBuffer是线程安全的。（可以在多线程的环境下使用不会出现问题）
StringBuilder是非线程安全的。（在多线程环境下使用可能出现问题）

===================================================================================================================================================

java中八种数据类型对应的包装类型
java.lang.Object -> java.lang.Number -> java.lang.Integer...意思就是在number这个包下的都是数字，
Number是抽象类

下面这两个特殊，因为这两个不是数字类型，所以特殊
java.lang.Object -> java.lang.Boolean
java.lang.Object -> java.lang.Character

byte          java.lang.Byte
short         java.lang.Short
int			  java.lang.Integer
long          java.lang.Long
float         java.lang.Float
double        java.lang.Double
boolean       java.lang.Boolean
char          java.lang.Character

思考：为什么Java要提供对应的包装类？
java中如果想接受byte类型的数据，可以先将byte类型先包装成java.lang.Byte;再传递参数
分为基本数据类型和引用数据类型，如果想传参数，既得传Object X;  又得传 int / short/ double X;  之类
包装起来，就只用传Objcet

public class IntegerTest01
{
	public static void m1(Object o)
	{
		System.out.println(o);
	}
	
	public static void main(String[] args)
	{
		//基本数据类型
		byte b = 10;
		
		//引用类型
		Byte b1 = new Byte(b);
		
		m1(b);   //10  Byte已经将object中的toString方法重写了
	}
}

——————————————————————————————————————————————————————————————————
byteValue() ......以byte形式返回指定的数值
获取int类型的最大值和最小值,其他同理
Ingeter是int的包装类，int的初值为0，Ingeter的初值为null
Integer.MIN_VALUE
Integer.MAX_VALUE

创建Integer类型的对象
Integer i1 = new Integer(10);  //int -->  Integer   10
Integer i2 = new Integer("122");    //String -->  Integer  122

//编译通过，运行不通过
//虽然可以将字符串转换成Integer类型，但是该字符串也必须是“数字字符串”
Integer i3 = new Integer("abcf");   //NumberFormaException


关于Integer中常用的方法
1.intValue 将引用类型转换位基本类型
  Integer i1 = new Integer(10);
  int i2 = i1.intValue();

2.parseInt 将字符串引用类型 转换成int

3.parseDouble 将字符串引用类型转换double

4.将int类型的十进制转换成二进制 八进制  十六进制
toBinaryString(int i)
toOctalString(int i)
toHexString(int i)

5.将int 转化为 Integer
Integer i = Integer.valueOf(10);

6.将String 转化成 Integer
Integer i = Integer.valueOf("10");


总结：
//1.int --> Integer
Integer i1 = Integer.valueOf(10);

//2.Integer -> int
int i2 = i1.intValue();

//3.String --> Integer
Integer i3 = Integer.valueOf("10");

//Integer --> String 
String s1 = i3.toString();  

//String --> int 
int i4 = Integer.parseInt("123");

//int -->String 
String s2 = 10 + "";

________________________________________________________________________
JDK5.0新特性
自动装箱（auto_boxing） 和  自动拆箱（auto_unboxing）

JDK5.0之前
int-->Integer (装箱)
Integer i1 = new integer(10);
Integer-->int (拆箱)
int i2 = i1.intValue();

JDK5.0之后
Integet i3 = 10;
int i4 = i3;

m1(321); //自动装箱 
public static void m1(Object o)
{
	System.out.println(o);
}

public sattic int m2(Integer i1, Integer i2)
{
	return i1 - i2;  //自动拆箱
}


深入自动装箱和自动拆箱
自动装箱和自动拆箱是编译阶段的一个概念，和程序运行无关
自动装箱和自动拆箱主要是为了方便程序员的编码

Integer i1 = new Integer(10);
Integer i2 = new Integer(10);

//这里不会自动拆箱
System.out.println(i1 == i2);  //false

//比较两个Integer类型的数据是否相等，不能用 == 
//应该是 i1.equals(i2)   Integer已经重写了equals方法

//重点 
Integer i3 = 128;
Integer i4 = 128;

Syatem.out.println(i3 == i4);  //false

//注意以下程序
//如果数据是在-128 - 127之间，java中引入了整型常量池，再方法区中
//该整型常量池只储存-128 ~ 127之间的数据
//只要new一个就有一个新的地址，下面没有显示的将new写出来
Integer i3 = 127;   //这个程序不会在队中创建对象，会直接从堆中拿   
Integer i4 = 127;

Syatem.out.println(i3 == i4);  //true

Integer i3 = -128;
Integer i4 = -128;

System.out.println(i3 == i4);  //true

================================================================================================================================================
日期类型
----------------------------------------------------------------------------
1.系统当前的毫秒数            System.currentTimeMillis();

2.获取系统当前时间            Date nowTime = new Date();
  获取1970年1秒钟之后的时间   Date t2 = new Date(1000);
  获取当前时间前十分钟的时间  Date t2 = new Date(System.currentTimeMillis() - 1000 * 60 * 10);
  
3.日期格式 		   SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS");
  调用输出         String strTime = sdf.【format】(nowTime);   println(strTime);
  获取特定的时间   String strTime = "2000年08月08日 08:08:08 888";
				   Data t = sdf.【parse】(strTime);
   
----------------------------------------------------------------------------
1.获取自1970年1月1日 00时00分00秒 000毫秒  到当前的 毫秒数

long now = System.currentTimeMillis();    //Millis的意思就是毫秒
System.out.println(now);   

2.获取系统当前时间
import java.util.Date;
Date nowTime = new Date();  //以上程序说明java.util.Date已经重写了Object中的toString方法

//所以引入格式化日期
java.util.Date; -->string

//创建日期格式化对象  就是日期显示在屏幕上就是这个形式
//按照中间大写，两边小写的方式
SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS");

//开始格式化(Date------>String)
String strTime = sdf.format(nowTime);


3.获取特定的日期
String strTime = "2000年08月08日 08:08:08 888";
SimpleDateFormat sdf  = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS");
Data t = sdf.parse(strTime);
//以中国的形式输出System.out.println(sdf.format(sdf.parse(strTime)));

注意：parse会抛出异常
public Date parse(String sourse)
			throws ParseException



4.Date d = new Date();  获取系统当前时间

import java.util.Date;
import java.text.SimpleDateFormat;

//1000是自1970-1-1 00:00:00 000的毫秒数
Date t1 = new Date(1000);
SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS");
sdf.format(t1);

//获取当前系统的前十分钟时间
//System.currentTimeMillis()是到目前的毫秒数
Date t2 = new Date(System.currentTimeMillis() - 1000 * 60 * 10)
System.out.println(sdf.format(t2));

5.日历
获取系统当前的日历
Calendar c = Calendar.getInstance();

查看当前日历的星期几
int i = c.get(Calendar.DAY_DF_WEEK);  //中国星期日，外国人看作第一天 3

是几号
c.get(Calendar.DAY_OF_MONTH);  //31


获取2008 8 8是星期几

//获取2008 8 8 的日历
String strTime = "2008年08月08日";
SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日").parse(strTime);   //从字符串中解析文本以产生一个Date

//该日历就是2008 8 8 的日历
/*
setTime(Date date) 
使用给定的 Date设置此日历的时间。 

*/
c.setTime(d);   //建立这个时间的日历

====================================================================================================================================================
数字类
关于数字格式化：java.textDeximalFormat;
数字的格式元素：#代表任意数字  
                ,千分位
				.小数点
				0不够补0
//创建数字格式化对象
//需求：加入千分位
DecimalFormat df = new DecimalFormat("###,###");

//开始格式化
//将一个数字number转化成String
System.out.println(df.format(1234567));  //"1,234,567"


//需求，加入千分位，保留两位小数
DecimalFormat df1 = new DecimalFormat("###,###.##");
System.out.println(df.format(1234567.123));  //"1,234,567.12"

//加入千分位，保留四位小数，并且不够补0
DecimalFormat df2 = new DecimalFormat("###,###.0000");
System.out.println(df2.format(1234567.123));  //"1,234,567.1230"

________________________________________________________________________
java.math.BigDecimal  该类型的数据精确度极高，适合做财务软件，财务软件中double类型精确度太低

//创建大数据
BigDecimal v1 = new BigDecimal(10);
BigDecimal v2 = new BigDecimal(20);

//做加法运算
//v1 + v2;  //错误：两个引用类型不能做加法运算

//必须调用方法执行加法运算
BigDecimal v3 = v1.add(v2);

===================================================================================================================================================

随机数
import java.util.Random;
//创建一个随机数生成器
Random r = new Random();

//生成int类型的随机数
int i = r.nextInt(101); //[0~100]之间的随机数


===================================================================================================================================================

枚举类型
定义一个方法，该方法的作用是计算两个int类型数据的商，如果计算成功，则该方法返回1，如果执行失败则该方法返回0
enum Result
{
	SUCCESS,FAIL   //成功和失败  //规范要求：大写
}

public static void main(String[] args)
{
	int a = 10;
	int b = 0;
	
	Result retValue = divide(a,b);
	
	if(retValue == Result.SUCCESS)
	{
		System.out.println("成功");
	}
	else if(retValue == Result.FAIL)
	{
		System.out.println("失败");
	}
}

public static int divide(int a, int b)
{
	try
	{
		int c = a / b;
		return result.SUCCESS;
	}
	catch(Exception e)
	{
		return result.FAIL;
	}
}
===================================================================================================================================================

集合
1.集合只能用来存储引用类型

            迭代器，集合获取到迭代器                         <<Interface>>					   可迭代的，所有的集合都是可迭代的
			之后，可以使用迭代器去遍						   Iterable  ----------------------迭代就是遍历
			历集合		  \									      ^
						   \									  |
						Iterator								  |
					    hasNext()<-----------------------------Collection------------只能存储引用类型，并且是单个存储
						next()
						remove()			  /                                         \
											List 						     			Set		
							/                 |             \                     /             \			
						ArrayList         LinkList        Vector               HashSet       SortedSet
																									   \
																									TreeSet
													
			1.List储存元素的特点：有序可重复   有序：存进去什么顺序，取出来还是什么顺序
			2.Set储存元素的特点：无序不可重复
			3.SortSet储存元素的特点：无序不可重复，但是储存进去的元素可以按照元素大小自动排序
			4.Arraylist底层采用数组储存元素的，所以ArrayList集合适合查询，不适合频繁随机增删元素
			5.LinkedList底层采用双向链表这种数据结构储存数据的
			6.Vector底层和ArrayList集合相同，但是Vector是线程安全的，效率较低，很少使用
			7.HashSet底层是一个HashMap
			————————————————————————————————————————————————————————————————————————————————————
			一、数组声明了它容纳的元素的类型，而集合不声明。
二、        数组：是静态的，一个数组实例具有固定的大小，一旦创建了就无法改变容量了。而集合是可以动态扩展容量，可以根据需要动态改变大小，集合提供更多的成员方法，能满足更多的需求。
三、        数组：的存放的类型只能是一种（基本类型/引用类型）,集合存放的类型可以不是一种(不加泛型时添加的类型是Object)。
四、        数组：是java语言中内置的数据类型,是线性排列的,执行效率或者类型检查都是最快的。
			
		
			————————————————————————————————————————————————————————————————————————————————————
			
			                                                    Map<Key,Value>
															           ^
			                            /                              |                                \
									HashMap                        HashTable                        SortedMap
																	   ^                                  \
																	   |                                TreeMap
																	   |
									                               Properties
																   
			1.Map集合以键值对的方式存储元素，键特点是：无序不可重复的。Map和collection没有关系
			2.HashMap：哈希表，hashMap中的key等同于一个Set集合
			3.Hashtable：线程安全的，效率低
			4.SortMap：SortMap中的Key储存元素的特点，无序不可重复，但是可以按照元素的大小顺序自动排序。SortMap中的Key等同于SortedSet
			5.TreeMap的Key就是一个TreeSet
			
2.使用java语言模拟单向链表

public class Linked
{
	Entry entry;
	
	Linked()
	{
		entry = new Entry(null,null);
	}
	
	//增
	//删
	//查
	static class Entry
	{
		Object data;
		Entry next;
		
		Entry(Object data, Entry next)
		{
			this.data = data;
			this.entry = entry;
		}
	}
}


3.collection集合

boolean add(Object element);  //向集合中添加元素
  
void clear() //清空集合

boolean contains(Object o)   //判断集合中是否包含某个元素，底层调的是equals方法
  
boolean isEmpty()    //判断集合中是否有元素


Iterator<E> iterator() //获取集合所依赖的迭代器对象
 
boolean remove(Object o)   //删除集合中某个元素

int size()   //返回此集合中的元素数。  
  
Object[] toArray()   //将集合转换成数组  


public class CollectionTest01
{
	public static void main(String[] args)
	{
		Collection c = new ArrayList();  //注意啊，这个是集合不是数组，集合继承了Object
		c.add(1);
		c.add(new Integer(100));
		
		Customer cus = new Customer("JACK",20);
		c.add(cus);
	}
}



class Customer
{
	String name;
	int age;
	
	Customer(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	
	public String toString()
	{
		return "Customer[name = "+name+", age = "+age+"]";
	}
}

————————————————————————————————————————————————————————————————

Iterator<E> iterator() //获取集合所依赖的迭代器对象
通过迭代器中的方法完成集合的迭代（遍历）
这种方式是所有集合通用的遍历方式

import java.util.*;
public class CollectionTest02
{
	public static void main(String[] args)
	{
		//创建对象
		Collection c = new ArrayList();
		
		//添加元素
		//会自动装箱
		c.add(100);   
		c.add(3.14);
		c.add(false);
		
		//迭代，遍历
		//获取迭代器对象
		//不需要关系底层集合的具体类型，所有集合依赖的迭代器都实现了java.util.Iterator;  接口
		Iterator it = c.iterator();  //迭代器是面向接口编程
		                             //it是引用，保存了内存地址，指向堆中的“迭代器对象”
		System.out.println(it);
		//java.util.LinkedList$ListItr 类是LinkList集合所依赖的迭代器
		//java.unil.AbstractList$Itr 类是ArrayList集合所依赖的迭代器
		
		//开始调用方法，完成遍历，迭代
		while(it.hasNext())
		{
			System.out.println(it.next();); //100  3.14  false
		}
		
		/*
			boolean b = it.hasNext();   判断是否有更多的元素，如果有返回true
			Object o = it.next();     将迭代器向下移动一位，并且取出指向的元素
		*/
	}
}

——————————————————————————————————————————————————————————————————————————————————
存储在集合中的元素应该从写equals方法
Manager m1 = new Manager(100,"Jack");
Manager m2 = new Manager(100,"Jack");
c.contains(m2);

class Manager
{
	int no;
	String name;
	
	Manager(int no, String name)
	{
		this.name = name;
		this.no = no;
	}
	
	//重写equals方法
	public boolean equals(Object o)
	{
		if(this == o)
			return true;
		if(o instanceof Manager)
		{
			Manager m = (Manager)o;
			if(m.no == this.no && m.name.equals(this.name))
			{
				return true;
			}
		}
		
		return false;
	}
}

——————————————————————————————————————————————————————————————————————————————————
深入remove方法
	1.迭代器自身remove方法
	2.集合自带的remove方法
	
Collection c = new ArrayList();
c.add(1);
c.add(2);
c.add(3);

//遍历
Iterator it = c.iterator();

while(it.hasNext())
{
	//推荐使用迭代器自身带的remove方法删除元素
	it.next();
	it.remove();
	
	//使用集合自身所带remove
	Object element = it.next();
	c.remove(element);  //这样删除之后，c中的元素改变，必须重新建立迭代器
	
}



4.List集合
	·特点：有序、可重复

import java.util.*;
List l = new ArrayList();   //因为只有List中才有get方法
l.add(100);
Iterator it = l.iterator();

while(it.hasNext())
{
	System.out.println(it.next());
}

————————————————————————————————————————————————————————————
深入List集合
/* Array集合底层是数组，数组是有下标的，所以ArrayList集合会有很多字节的特性
ArrayList集合底层默认初始化容量是10，扩大之后容量是原容量的1.5 倍。
Vector集合底层默认初始化容量也是10，扩大之后的容量是原容量的2倍

如何优化ArrayList和Vector
尽量减少扩容操作，因为扩容需要数组拷贝，数组拷贝很耗内存。一般推荐在创建集合的时候指定初始化容量 */

List l = new ArrayList();  //可以自定义容量   List l = new ArrayList(100);
l.add(123);
l.add(321);
l.add(69);

//在下标为1的位置上添加555
l.add(1,555);
	 
for(int i = 0; i < l.sizeof(); i++
{
	Object element = l.get(i);
	System.out.println(element);
}

//迭代器也可以


5.Set接口
/*
	1.HashSet底层实际上是一个HashMap，HashMap底层采用了哈希表的数据结构
	
	2.哈希表又叫做散列表，散列表底层是一个数组，这个数组中每一个元素是一个单向链表，每个单向链表都有一个独一无二的hash值
	  ，代表数组的下标，在某个单向链表中的每一个节点上的hash值是相同的。hash值实际上是key调用hashCode方法，通过“hash function”转换成的值
	  
	3.如何向哈希表中添加元素：
	  先调用被储存的key的hashCode方法，经过某个算法的出hash值，如果在这个哈希表中不存在这个hash值，则直接加入元素，如果该hash值已存在
	  继续调用key之间的equals方法，继续调用key之间的equals方法，如果equals方法返回false，则将该元素添加。如果equals方法返回true，则放弃
	  添加该元素
	  
	4.HashSet其实是HashMap中的key部分。HashSet有什么特点，HashMap中的Key应该具有同样的特点
	
	5.HashMap和HashSet初始化容量都是16，默认加载因子是0.75
*/

Set s = new HashSet();
s.add(1);
s.add(1);
s.add(100);
s.add(109);
s.add(136);

Iterator it = s.iterator();
while(it.hashNext())
{
	System.out.println(it.next());
}



6.HashSet方法

/*
	关于往Set集合中储存的元素，该元素的hashCode和equals方法
	HashMap中有一个put方法，put(key,value) key是无序不可重复的
*/
import java.util.*;
public class Set
{
	public static void main(String[] args)
	{
		//创建集合
		Set es = new HashSet();
		
		Employee e1 = new Employee("1000","JACK");
		Employee e2 = new Employee("2000","JCK");
		Employee e3 = new Employee("3000","JAK");
		Employee e4 = new Employee("4000","ACK");
		Employee e5 = new Employee("5000","JAC");
		Employee e6 = new Employee("6000","JA");
		
		//添加元素
		es.add(e1);
		es.add(e2);
		es.add(e3);
		es.add(e4);
		es.add(e5);
		es.add(e6);
		
		//查看集合中元素个数
		System.out.println(es.size());
		
	}
}


//根据现实的业务逻辑得知，该公司员工编号是：1000 - 9999
class Employee
{
	String no;
	String name;
	
	Employee(String no, String name)
	{
		this.no = no;
		this.name = name;
	}
	
	//重写equals方法
	//如果员工编号相同，并且名字也相同，则是同一个对象
	public boolean equals(Object o)
	{
		if(this == o)
		{
			return true;
		}
		
		if(o instanceof Employee)
		{
			Employee e = (Employee)o;
			if(o.no.equals(this.no) && e.name.equals(this.name))
			{
				reutnr true;
			}
		}
		
		return false;
	}
	
	//重写hashCode方法
	//根据hashCode找到的是位置,上面的equals是如果位置相同，比较元素是否相同，因为hashCode是根据地址得出的hashCode值，如果是这样的话（小明，001）
	//和(小明，001)就不是一个人
	public int hashCode()
	{
		return (no / 1000).hashCode();  //no是String类型，这个类中重写了hashCode方法
	}
	
}


7.TreeSet方法
无序不可重复，但是存进去的元素可以按照元素大小顺序自动排列

            迭代器，集合获取到迭代器                         <<Interface>>					   可迭代的，所有的集合都是可迭代的
			之后，可以使用迭代器去遍						   Iterable  ----------------------迭代就是遍历
			历集合		  \									      ^
						   \									  |
						Iterator								  |
					    hasNext()<-----------------------------Collection------------只能存储引用类型，并且是单个存储
						next()
						remove()			  /                                         \
											List 						     			Set		
							/                 |             \                     /             \			
						ArrayList         LinkList        Vector               HashSet       SortedSet
																									   \
																									TreeSet
SortedSet集合为什么可以实现自动排序？
因为被储存的元素实现了Comparable接口，SUN编写TreeSet集合在添加元素的时候会调用compareTo方法进行比较
因为实现了comparable接口

---------------------------------------
Comparable 和 Comparator的区别
一个类实现了Comparable接口则表示这个类的对象之间是可以相互比较的
，这个类对象组成的额集合就可以直接使用sort方法排序
Comparator可以看成一种算法的实现，将算法和数据分离
---------------------------------------

User u1 = new User(15);
Iterator it = users.iterator();
。。。。。

//如果是自己定义的类。就没有实现comparable接口
class User implements Comparable
{
	String name;
	int age;
	
	User(int age)
	{
		this.age = age;
	}
	
	public String toString()
	{
		return "User[age = "+age+"]";
	}
	
	//实现java.lang.Comparable;接口中的compareTo方法
	//该方法程序员负责实现，SUN提供的程序已经调用了该方法
	//需求：按照User的age排序
	public int compareTo(Object o)
	{
		int age1 = this.age;
		int age2 = ((User)o).age;
		return age2 - age1;
	}
}																									

——————————————————————————————————————————————————————————————————
单独编写一个比较器

//创建TreeSet集合的时候提供一个比较器
SortedSet products = new TreeSet(new ProductComparator());


class Product
{
	double price;
	
	Product(double price)
	{
		this.price = price;
	}
	
	public String toString()
	{
		return price + "";
	}
}


单独编写一个比较器
class ProductComparator implements Comparator
{
	//需求：按照商品价格排序
	public int compare(Object o1, Object o2)
	{
		double price1 = ((Product)o1).price;
		double price2 = ((Product)o2).price;
		
		if(price1 == price2)
			return 0;
		else if(prices1 > price2)
			return 1;
		else
			return -1;
		
	}
}


也可以写一个匿名内部类，但是比较器不能多次重复利用，不推荐
SortedSet products = new TreeSet(new Comparator()
{
	//需求：按照商品价格排序
	public int compare(Object o1, Object o2)
	{
		double price1 = ((Product)o1).price;
		double price2 = ((Product)o2).price;
		
		if(price1 == price2)
			return 0;
		else if(prices1 > price2)
			return 1;
		else
			return -1;
		
	}
}
);

=====================================================================================================================================================
			
			
			                                                    Map<Key,Value>
															           ^
			                            /                              |                                \
									HashMap                        HashTable                        SortedMap
																	   ^                                  \
																	   |                                TreeMap
																	   |
									                               Properties
																   
			1.Map集合以键值对的方式存储元素，键特点是：无序不可重复的。Map和collection没有关系
			2.HashMap：哈希表，hashMap中的key等同于一个Set集合
			3.Hashtable：线程安全的，效率低
			4.SortMap：SortMap中的Key储存元素的特点，无序不可重复，但是可以按照元素的大小顺序自动排序。SortMap中的Key等同于SortedSet
			5.TreeMap的Key就是一个TreeSet

1.
void clear()  清空Map
 
boolean containsKey(Object key)  判断Map中是否包含这样的key

boolean containsValue(Object value) 判断Map中是否包含这样的value
 
Set<Map.Entry<K,V>> entrySet() 
返回此地图中包含的映射的Set视图。  
  
V get(Object key)   通过key获取value

boolean isEmpty() //判断该集合是否为空
 
Set keySet()    //获取Map中所有的key

V put(K key, V value)    //向集合中添加键值对

V remove(Object key)     //通过key将键值对删除

int size()           //获取Map中键值对的个数
  
Collection<V> values()   //获取Map集合中所有的value


import java.util.*;

public class MapTest01
{
	public static void main(String[] args)
	{
		//创建Map集合
		//如果Map中的key重复，采用用覆盖的方法
		Map persons = new HashMap(); //HashMap的默认初始化容量是16，默认加载因子0.75
		persons.put("10000","JACK");
		persons.put("10001","ALICE");
		persons.put("10002","BEN");
		persons.put("10003","KING");
		persons.put("10004","LUCY");
		persons.put("10005","JACK");
		
		
		System.out.println(persons.size());
		
		System.out.println(persons.containKey("10000"));
		
		System.out.println(persons.containsValue("BEN"));
		
		String k = "10002";
		Object v = persons.get(k);
		System.out.println(v);
		
		persons.remove("10002");
		System.out.println(persons.size());
		
		//获取所有的value
		Collection values = persons.values();
		Iterator it = values.iterator();
		while(it.hasNext())
		{
			System.out.println(it.next());
		}
		
		//获取所有的key
		Set keys = persons.keySet();
		
		Iterator it2 = keys.iterator();
		
		while(it2.hasNext())
		{
			Object id = it2.next();
			Object name = persons.get(id);
			System.out.println(id + "->" + name);
		}
		
		_______________________________________________________________
		//将Map转换为Set集合，不多，上面的那个灵活
		Set Enterset = persons.entrySet();
		
		Iterator it3 = Enterset.iterator();
		while(it3.hasNext())
		{
			System.out.println(it3.next());
		}
	}
}


2.HashMap的默认初始化容量是16，默认加载因子0.75
  Hashtable默认初始化容量是11，默认加载因子0.75
  java.util.Properties;也是由key和value组成，但是key和value都是字符串类型
  
  Properties p = new Properties();
  p.setProperty("...", "...");
  
  //通过key获取value
  String v1 = p.getProperty("...");

=====================================================================================================================================================
SortedMap
SortedMap中的key特点：无序不可重复，但是存进去的元素可以按照大小自动排列
如果想自动排序，key部分的元素需要： 1.实现Comparable接口  2.单独写一个比较器
public class SortedMapTest01
{
	public static void main(String[] args)
	{
		//Map, key存储Product，value存储个数
		SortedMap products = new TreeMap();
		
		//准备对象
		Product p1 = new Product("西瓜",1.0);
		Product p2 = new Product("苹果",6.0);
		Product p3 = new Product("橘子",8.0);
		Product p4 = new Product("香蕉",3.0);
		
		//添加
		produte.put(p1,9);
		produte.put(p2,9);
		produte.put(p3,9);
		produte.put(p4,9);
		
		Set keys = products.keySet();
		Iterator it = keys.iterator();
		
		while(it.hasNext())
		{
			Object k = it.next();
			Object v = products.get(k);
			System.out.println("k + "---->" + v + "个"");
		}
	}
}


class Product implements Comparable
{
	String name;
	double price;
	
	Product(String naem, double price)
	{
		this.name = name;
		this.price = price;
	}
	
	public String toString()
	{
		return "Product[name = "+name+", price = "+price+"]"
	}
	
	//实现compareTo方法
	//需求：按照商品价格排序
	public int compareTo(Object o)
	{
		double price1 = this.price;
		double price2 = ((Product)o).price;
		
		if(price1 < price2)
			return -1;
		else if(price1 > price2)
			return 1;
		else
			return 0
	}
	
}

=====================================================================================================================================================
Collections  工具类
java.util.Collection;集合接口

//使用Collection工具完成集合的排序
List l = new ArrayList();

//添加元素
l.add(10);
l.add(4);
l.add(6);
l.add(1);
l.add(19);

//遍历
for(int i = 0; i < l.size(); i++)
{
	System.out.println(l.get(i));
}

for(Iterator it = i.iterator(); it.hasNext() ;)
{
	System.out.println(it.next();
}


//排序
Collections.sort(i);

for(Iterator it = i.iterator(); it.hasNext() ;)
{
	System.out.println(it.next();
}


_______________________________________________________________

Set a = new HashSet();

//添加元素
a.add(10);
a.add(4);
a.add(6);
a.add(1);
a.add(19);

//将Set集合转换成List集合
List Lists = new ArrayList(a);

Collections.sort(Lists);

//遍历
for(int i = 0; i < l.size(); i++)
{
	System.out.println(l.get(i));
}

————————————————————————————————————————————————————————————————
Collections工具类可以对List集合中的元素排序，但是集合中的元素必须是可比较的，实现comparable接口

//将ArrayList集合转换成线程安全的
List myList = new ArrayList();
Collections.synchronizedList(myList);

====================================================================================================================================================
JDK5.0新特性
1.泛型（编译期）
	·为什么引入泛型
		可以统一集合中的数据类型
		可以减少强制类型转换
	·泛型语法如何实现
		泛型是一个编译阶段的语法，在编译阶段同意集合中的类型
	·泛型的优点和缺点
		优点：同一类型，减少强制转换
		缺点：类型太统一了，只能存储一种类型

//以下程序没有使用泛型，缺点
如果集合不使用泛型，则集合中的元素类型不同意，在遍历集合的时候，只能拿出来Object类型，需要做大量的强制类型转换，麻烦

public class Test
{
	public static void main(String[] args)
	{
		//创建一个集合。存储数据
		Set s = HashSet();
		
		A a = new A();
		B b = new B();
		C c = new C();
		
		s.add(a);
		s.add(b);
		s.add(c);
		
		//需求：遍历集合，如果是A类型调用m1方法，B类型调用m2方法。C类型调用m3方法
		Iterator it = s.iterator();
		while(it.hasNext())
		{
			Object o = it.next();
			
			//只能做大量的强制类型转换
			if(o instanceof A)
			{
				A a1 = (A)o;
				a1.m1();
			}
			else if(o instanceof B)
			{
				B b1 = (B)o;
				b1.m2();
			}
			else if(o instanceof C)
			{
				C c1 = (C)o;
				c1.m3();
			}
			
		}
		
	}
}

class A
{
	public void m1()
	{
		System.out.println("1");
	}
}

class B
{
	public void m2()
	{
		System.out.println("2");
	}
}


class C
{
	public void m3()
	{
		System.out.println("3");
	}
}

————————————————————————————————————————————————————————————————
只要在帮助文档中使用<>都能使用泛型
//创建一个List集合，只能存储字符串类型
List<String> strs = new ArrayList<String>();

//添加元素
strs.add(1);  //不行，必须是String类型

strs.add("JACK");

//遍历
Iterator<String> it = strs.iterator();

while(it.hasNext())
{
	String s = it.next();
	System.out.println(s);
}

_______________________________________________________________

Map使用泛型
Map<String,Integer> maps = new HashMap<String,Integer>();

maps.put("西瓜"，10);

Set<String> keys = maps.keySet();
Iterator<String> it = keys.iterator();

while(it.hasNext())
{
	String k = it.next();
	Integer v = maps.get(k);
	System.out.println("k + "----->" + v");
}

__________________________________________________________________
SortedSet集合使用泛型

SortedSet<Manager> ss = new TreeSet<Manager>();

//添加
Manager m1 = new Manager(100.0);
ss.add(m1);

//遍历
Iterator<Manager> it = ss.iterator.iterator();
while(it.hasNext())
{
	Manager m = it.next();
	System.out.println(m.toString);
}



class Manager implements Comparable<Manager>
{
	double sal;
	
	Manager(double sal)
	{
		this.sal = sal;
	}
	
	public String toString()
	{
		return sal + "";
	}
	
	public int compareTo(Manager m)   //这个和接口中的相同Manager
	{
		double sall = this.sal;
		double sal2 = m.sal;    //不需要强转了
		
		if(sal1 > sal2)
			return 1;
		else if(sal1 < sal2)
			return -1;
			
		return 0;
	}
}

——————————————————————————————————————————————————————————————————
自定义泛型

MyClass<String> mc = new MyClass<String>();

//编译无法通过
mc.m1(100);

mc.m1("JACK");

class MyClass<T>
{
	public void m1(T t)
	{
		System.out.println(t);
	}
}

======================================================================================================================================================
JDK5.0新特性——增强for循环
语法： 
	for(类型 变量：变量名/集合名) {}
	
	集合想要使用for循环这种语法，集合需要使用泛型
	如果不使用泛型，需要用Object类型定义元素
	
int[] a = {1, 2, 3, 4, 5, 6};

for(int e : a)
{
	System.out.println(e);
}
_____________________________________________________

//集合
Set<String> strs = new HashSet<String>();

strs.add("梅塔塔");

for(String name:strs)
{
	System.out.println(name);
}

//集合不使用泛型
List l = new ArrayList();
l.add(1);

//如果集合不使用泛型，该集合在用增强for循环的时候应该用Object类型定义
for(Object element : l)
{
	System.out.println(element);
}

———————————————————————————————————————————————————————————————————————
关于增强for的缺点：没有下标
 String[] ins = {"运动","音乐","旅游","美食"};
 StringBuffer sb = new StringBuffer();
 for(int i = 0; i < ins.length; i++)
 {
	 
	 if(i == ins.length - 1)
	 {
		 sb.append(ins[i]);
	 }
	 else
	 {
		 sb.append(ins[i]);
		 sb.append(",");
	 }	
 }
 
 //以上的循环就不适合使用增强for
 for(String s : ins)
 {
	 sb.append(s);
	 sb.append(",");
 }
 
 //截取调
 System.out.println(sb.substring(0,sb.length() - 1));



======================================================================================================================================================
 =======
|  流   |
 =======
1.分类
  流根据方向可以分为，输入流和输出流。注意，输入流和输出流是相对于内存而言的。从内存出来就是输出，到内存中就是输入
  输入流又叫做InputStream，输出流又叫做OutputStream。输入还叫作“读 Read”，输出还叫做“写 Write”

    |                  迅雷服务器                    |                  本地计算机					  |
  硬盘————————————————————————————>内存————————————————————————————>内存————————————————————————————>硬盘
                    ^								 ^
					|								 |
				  输入流					   	   输出流
  
                             相当于这个内存而言

  流根据读取数据的方式可以分为：字节流和字符流，字节流是按照字节的方式读取，字符流是按照字符的方式读取，一次读取两个字节，Java语言中一个字符占
                                两个字节
								
								字节流适合读取，视频，声音，图片等二进制文件
								字符流适合读取：纯文本文件
								
								Java语言中所有的字节流都以Stream结尾，所有的字节流都含有Reader或Writer
    
2.需要掌握的16个流
FilmInputStream
FilmOutputStream
FilmReader
FilmWriter

带有缓冲区的四个流
BufferedReader
BufferedWriter
BufferedInputStream
BufferedOutputStream

DataInputStream
DataOutputStream

ObjectInputStream
ObjectOutputStream

//转换流（字节流转换成字符流）
InputStreamReader
OutputSteamWriter

PrintWriter
PrintStream  //标准的输出流（默认输出到控制台）
====================================================================================================================================================
异常：FileNotFoundException;
这四个流水流直达文件
1.创建流
xxx = new xxx("文件名")；//里面可以填相对路径，也可以填绝对路径
		        //如果是输出流，注意是覆盖输出，还是接后输出
		        //接后输出("文件名"， true);

2.创建句段容纳器
①字节类型——创建字节类型容纳器——就是在读取和输入的时候必须是字节的形式
FilmInputStream
byte[] bytes = new byte[3];
---------------------------
FilmOutputStream
如果要输出的是 String msg = "HelloWorld";   因为必须是以字节方式进行传输，将String转化成byte
byte[] bytes = msg.getBytes();

②字符类型
FilmReader
char[] chars = new char[512];

FilmWriter


2.创建读取的个数
temp = 0

3.读取 / 写入
①读取
temp = read ();   //返回值就是成功读取的个数，达到结尾，返回-1
             	           //如果括号里什么都没有，就是每次读取一个字节
	           //如果是   read(bytes / chars);  并将成功读取的字节储存到bytes / chars数组中		

②写入
字节形式
xxx.write(bytes, 0, 3);
--------------------
字符形式
xxx.write(“我是梅宝仔”);

char[] chars = {'我','爱','梅','塔','塔'};
fw.write(chars, 0, 3);

4.输出bytes数组中所储存的值
如果想要输出，先将Unicode码转化成字符，再调用toString方法输出
而String类中转化并输出的方法，所以
new String(bytes);    //如果想要输出成功读取的  new String(bytes, 0, temp);
new String(chars);   //如果想要输出成功读取的  new String(chars, 0, temp);

4.强制写入 + 关闭 
bytes.flush();   
xxx.close();

————————————————————————————————————————

这四个流都是带有缓冲区的，意思就是水流可以在下面四个里保存，意思就是把上面的流包装了
BufferedReader
BufferedWriter
BufferedInputStream
BufferedOutputStream

首先你得知道输到哪里，这只是一个储存的机器
BuffereReader br = new BuffereReader(new FileReader("xxx"));  //所以构造的时候应该这样构造
因为他现在是一个储存器了，所以就可以一行一行的储存，也就是可以一行一行的读
读出来的一行放入到String中
String temp = null;
while((temp = br.readLine() != null))   //br.readLine()方法读取一行，但是行尾不带换行符
{
	System.out.println(temp);  //输出一行
}
		
关闭的时候关闭最外面的包装流br.close();	
			
		

转换流（字节流转换成字符流）,这只是一个转换的机器
InputStreamReader
OutputSteamWriter

——————————————————————————————
DataInputStream
DataOutputStream

ObjectInputStream
ObjectOutputStream

PrintWriter
PrintStream  //标准的输出流（默认输出到控制台）


===================================================================================================================================================


3.Java语言中的流分为：InputStream、OutputStream、reader、Writer
_____________________________________________________________________________________________________________________________________________________
															  字节输入流

                                                                接口                                          接口
															  Closeable                                    Flushable
															    实现类                                       实现类
															   Close()                                      flush()
															   
							
							  /																					\
	                     InputStream	 															       OutputStream											

       /                      |                       \                                   /                       |                        \
FilmInputStream        FilerInputStream        ObjectInputStream                   FilmOutputStream        FilerOutputStream       ObjectOutputStream                 

                /                        \                                                           /                         \
       BufferedInputStream         DataInputStream											BufferedInputStream         DataInputStream


_____________________________________________________________________________________________________________________________________________________
                                                                     字符输入流


											接口                                                       接口
										  Closeable                                                 Flushable
											实现类                                                    实现类
										   Close()                                                    flush()

                               /                                                                        \ /
							Reader                                                                     Writer
 
       /                                      \                                /                          |                        |
InputStreamReader                       BufferedReader                 OutputSteamWriter            BufferedWriter            PrintWriter
       |                                                                       |
  FilmReader                                                               FileWriter


  
1.FilmInputStream
public class Test
{
	public static void main(String[] args)
	{
		FilmInputStream fis = null;
		
		try
		{
			//要读取文件，先与这个文件创建一个输入流
			//文件路径String filePath = "temp01";   //相对路径，相对当前而言，在当前路径下寻找
			//绝对路径
			//String filePath = "C:\\Users\\小可爱\\Documents\\MyJava\\javaProject\\Java-SE\\chapter-03\\temp01";
			                    //C:\Users\小可爱\Documents\MyJava\javaProject\Java-SE\chapter-03原本是这样，但是有转义字符，要把所有的\转换成\\
								//C:/Users/小可爱/Documents/MyJava/javaProject/Java-SE/chapter-03也可以这样把\全换成/
			fis = new FileInputStream(filePath);
			
			//开始读
			int i1 = fis.read();  //一个这样就只能读一个英文单词，以字节的方式读取，引文单词所占一个字节
								  //如果没东西了，输出的是-1
								  //汉字所占是占两个字节
			System.out.println(i1);  
			
								
		}
		catch(FilmNotFoundException e)
		{
			e.printStackTrace();
		}
		catch(IOException)
		{
			e.printStackTrace();
		}
		finally
		{
			//为了保证流一定会释放，所以在finally语句块中执行
			if(fis != null)
			{
				try
				{
					fis.close();
				}
				catch(IOException)
				{
					e.printStackTrace();
				}
			}
		}
	}
}

————————————————————————————————————————————————————————————————
//以下程序存在缺点，频繁访问磁盘，伤害磁盘，并且效率低
public class FilmInputStreamTest
{
	public static void main(String[] args) throws Exception
	{
		FilmInputStream fis = new FileInputStream("temp01");
		
		int temp = 0;
		
		while((temp = fis.read()) != -1)
		{
			System.out.println(temp);
		}
		
		fis.close();
	}
}


————————————————————————————————————————————————————————————
/* 
		int read(byte[] bytes);
		读取之前在内存中准备一个byte数组，每次读取多个字节存储到byte数组中，一次读取多个字节，不是单字节读取了，效率高 
*/
public class FilmInputStreamTest
{
	//假设文件中有abcdefg
	public static void main(String[] args) throws Exception
	{
		FilmInputStream fis = new FileInputStream("temp01.txt");
		
		byte[] bytes = new byte[3];   //每一次最多读取3个字节
		
		————————————————————————————————————————————————————————————
		
		//该方法返回的int类型的值代表的是，这次读取了多少个字节
		int i1 = fis.read(bytes);  //3
		
		//将byte数组转化成字符串
		System.out.println(new String(bytes));  //abc
		
		————————————————————————————————————————————————————————————
		
		int i2 = fis.read(bytes);  //3
		System.out.println(new String(bytes));  //def
		
		————————————————————————————————————————————————————————————
		
		int i3 = fis.read(bytes);  //1
		System.out.println(new String(bytes));  //gef
		
		//如何只输出g
		System.out.println(new String(bytes,0,i3));  //g  i3代表的是成功读取的个数
		————————————————————————————————————————————————————————————
		
		System.out.println(i1);
		System.out.println(i2);
		System.out.println(i3);
		System.out.println(i4);
		
		fis.close();
	}
}


————————————————————————————————————————————————————————————

public class FilmInputStreamTest
{
	public static void main(String[] args) throws Exception
	{
		FileInputStream fis = new FileInputStream("temp01");
		
		//循环读取
		byte[] bytes = new byte[1024]; //每次读取1KB
		while(true)
		{
			int temp = fis.read(bytes);
			if(temp == -1)
				break;
			
			//将byte数组中有效的数据转换成字符串
			System.out.print(new String(bytes, 0, temp));
		}
		
		——————————————————————————————————————————————————————
		
		//升级循环
		int temp = 0;
		while(temp = fis.read(bytes) != -1)
		{
			System.out.print(new String(bytes, 0, temp));
		}
		
		
		fis.close();
	}
}


———————————————————————————————————————————————————————————————————————

public class FilmInputStreamTest
{
	public static void main(String[] args) throws Exception
	{
		FilmInputStream fis = new FilmInputStream("temp");
		
		Sytem.out.println(fis.available()); //返回流中剩余的估计字节数
		
		//跳过两个字节
		fis.skip(2);
		
		fis.close();
	}
}

2.FileOutputStream：文件字节输出流
将计算机内存中的数据写入硬盘文件中

import java.io.*;
public class FilmInputStreamTest
{
	public static void main(String[] args) throws Exception
	{
		FileOutputStream fos = null;
		try
		{
		    //不是追加的方式，会把源文件覆盖，谨慎使用
			fos = new FileOutputStream("Test");   //该文件不存在会自动创建
			
			//以追加的方式写入,不会把源文件覆盖
			fos = new FileOutputStream("temp02", true);
			
			String msg = "HelloWorld";
			
			//将String转换成byte数组
			byte[] bytes = msg.getBytes();  //一个英文单词是一个字节
			fos.write(bytes);
			
			//将byte数组的一部分写入
			fos.write(bytes, 0, 3);
			
			//推荐最后的时候为了保证数据完全写入硬盘，所以要刷新
			fos.flush(); //强制写入
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(fos != null)
			{
				try
				{
					fos.close();
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
			}
		}
	}
}


——————————————————————————————————————————————————————————————————————————————————

关于文件的复制，粘贴
public class Copy01
{
	public static void main(String[] args) throw Exception
	{
		//创建输入流
		FileInputStream fis = new FileInputStream("这个文件的路径 + abc.txt");
		
		//创建输出流
		FileOutputStream fos = new FileOutputStream("这个文件想放到的路径 + abc.txt");
		
		//一边读，一边写
		byte[] bytes = new byte[1024];  
		int temp = 0;
		while((temp = fis.read(bytes)) != -1)   //我感觉这个read就是把字符转化成字节，write就是把字节转化成字符
		{
			//将byte数组中的内容直接写入
			fos.write(bytes, 0, temp);
		}
		
		
		//刷新
		fos.flush();
		
		//关闭
		fis.close();
		fos.close();
	}
}


——————————————————————————————————————————————————————————————————————————————————
3.FilmReader
/*
	java.io.Reader;
		java.io.InputStreamReader;   //转换流（字节输入流---->字符输入流）
			java.io.FileReader;      //文件字符输入流

*/

import java.io.Reader;
public class FilmInputStreamTest
{
	public static void main(String[] args) throws Exception
	{
		
		FileReader fr = null;
		try
		{
			//创建文件字符输入流
			fr = new fileReader("XXX");
			
			//开始读取
			char[] chars = new char[512];  //1KB
			
			int temp = 0;
			
			while(temp = fr.read(chars) != -1)
			{
				System.out.print(new String(chars, 0, temp));
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			if (fr != null)
			{
				try
				{
					fr.close();
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
			}
		}
	}
}


——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
4.FileWriter
java.io.Writer;
	java.io.OutputStreamWriter;   //转换流（字节输出流--->字符输出流）
		java.io.FileWriter;      //文件字符输出流
		
public class Film
{
	public static void main(String[] args) throw Exception
	{
		FilmWriter fw = new FilmWriter("temp03");  //覆盖
		FilmWriter fw = new FilmWriter("temp03",true); //追加
		
		//开始写
		fw.write("李海波！！！！");
		
		//将char数组的一部分写入
		char[] chars = {'我','爱','梅','塔','塔'};
		
		fw.write(chars, 0, 3);
		
		fw.flush();
		fw.close();
	}
}



//文件复制
//只能复制纯文本文件
public class Film
{
	public static void main(String[] args) throw Exception
	{
		FileReader fr = new FileReader("Film");
		
		FileWriter fw = new FileWriter("。。。");
		
		char[] chars = new char[512];
		int temp = 0;
		
		while((temp = fr.read(char) != -1))
		{
			fw.write(chars,0,temp);
		}
		
		fw.flush();
		fr.close();
		fw.close();
	}
}

———————————————————————————————————————————————————————————————————————
5.BufferedWriter
/*
	字符
	BufferedReader    带有缓冲区的字符输出流
	BufferedWriter    带有缓冲区的字符输出流
	
	字节
	BufferedInputStream   
	BufferedOutputStream
*/


public static Test
{
	public static void main(string[] args) throws Exception
	{
		//创建一个带有缓冲区的额字符输入流
		/*
		FileReader fr = new FileReader("xxx");    //创建一个文件字符输入流
		BufferedReader bf = new BufferedReader(fr);      //将文件字符输入流包装成带有缓冲区的字符输入流
		*/
		
		BufferedReader br = new BufferedReader(new FileReader("xxx"));
		
		//根据流出现的位置，流又可以分为：包装流或者处理流 和 节点流
		FilmReader fr 是一个节点流
		BuffereReader br 是一个包装流，或者处理流
		
		//开始读取
		//这个也很 好理解吗，因为要读取一行，所以读取的形式是字符串形式，字符串在java中就是String，而String对应一个类，所以要判断是否为空
		String temp = null;
		while((temp = br.readLine() != null))   //br.readLine()方法读取一行，但是行尾不带换行符
		{
			System.out.println(temp);  //输出一行
		}
		
		
		//关闭
		//注意：关闭的时候只需要关闭最外层的包装流。（这里有一个装饰着模式）
		br.close();
		
	}
}

---------------------------------------------------------------------------------------------------
public static Test
{
	public static void main(string[] args) throws Exception
	{
		/*
		//以前的方式
		//System类的构造方法是private的，所以无法创建该类的对象，也就是无法实例化该类。他的属性和方法都是static的，所以也可以很方便的进行调用。
		//创建流就意味着打开一条通道
		Scanner s = new Scanner(System.in);  //System.in是一个标准的输入流，默认接受键盘的输入
		
		//程序运行到此处停下来，等待用户的输入
		String str = s.next();
		System.out.println(str);
		*/
		
		//使用BufferedReader用来接收用户的输入
		/*
			nextInt()在读取输入后将光标放在同一行中。 
			next()它不能读两个由空格分隔的单词。另外，在读取输入后将光标放在同一行中 。 
			nextline()在读取输入之后，将光标放在下一行。66			
		*/
		BufferedReader bf = new BuffereReader(new InputStreamReader(System.in));   //前面new的是说明类型，（这个里面是说明源头）
		String str = br.readLine();
		System.out.println(str);
		
		br.close();
	}
}



---------------------------------------------------------------------------------------------------
5.InputStreamReader
public static Test
{
	public static void main(string[] args) throws Exception
	{
		/*
		//创建带有缓冲区的字符输入流
		FileInputStream fis = new FileInputStream("xxx");   //文件字节输入流
		
		//转换流（将字节流转换成字符流）
		InputStreamReader isr = new InputStreamReader(fis);  //isr是字符流
		
		BufferedReader bf = new BuffereReader(Reader);
		*/
		
		BufferedReader bf = new BuffereReader(new InputStreamReader(new FileInputStream("xxx")));
		
		//开始读
		String temp = null;
		while(temp = br.readLine() != null)
		{
			System.out.println(temp);
		}
		
		//关闭，关闭最外层的流即可，（装饰者模式）
		br.close();
	}
}

====================================================================================================
6.BufferedWriter
public static Test
{
	public static void main(string[] args) throws Exception
	{
		//如果是Writer形式，必须是字符串的流，而FileWriter正好是字符串的流
		BufferedWriter bw = new BufferedWriter(new FileWriter("temp04"));
		//这个也必须是字符串的流，可以使用FileReader，所以只能转换，将字节流转化成成字符流
		BufferedReader bw = new BuffereReader(new OutputStreamReader(new FileOutputStream("temp04",true)));
		
		bw.write("奥运会");
		
		//写入一个行分割符
		bw.newLine();
		
		bw.write("开幕式一点都没意思");
		
		bw.flush();
		bw.close();
	}
}

------------------------------------------------------------------------------------------------------------
使用BufferedReader 和 BufferedWriter 完成复制
public static Test
{
	public static void main(string[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FilmReader("xxx"));
		BufferedWriter bw = new BufferedWriter(new FilmWriter("xxx"));
		
		String temp = null;
		while((temp = br.readLine()) != null)
		{
			bw.write(temp);
			bw.newLine();
		}
		
		bw.flush();
		br.close();
		bw.close();
	}
}
  
====================================================================================================================================================
FilmInputStream
FilmOutputStream
FilmReader
FilmWriter

带有缓冲区的四个流
BufferedReader
BufferedWriter
BufferedInputStream
BufferedOutputStream

DataInputStream
DataOutputStream

ObjectInputStream
ObjectOutputStream

//转换流（字节流转换成字符流）
InputStreamReader
OutputSteamWriter

PrintWriter
PrintStream  //标准的输出流（默认输出到控制台）

装饰者模式()
1.对已有的类型进行扩展，以前的得输出，还得输出新的
就是将装饰者和被装饰者都实现一个抽象类，并实现抽象类中的方法
在装饰着中应该有被装饰者对象，扩展方法，并将对象.方法也加进去

//思考：对FileReader这个类的close方法进行扩展
//1.继承——不推荐，代码耦合度太高，不利于项目的扩展
//2.装饰者模式

public abstract class Reader
{
	public abstract void close();
}

//对FileReader中的close方法进行扩展
public class FilmReader extends Reader
{
	public void close()
	{
		System.out.println("我是最美丽");
	}
	
}
  
//使用BufferedReader对FileReader进行扩展

//1.装饰着模式中要求，装饰这种含有被装饰者的引用
//2.装饰者模式中要求：装饰者和被装饰者应该实现同一个类型
public class BufferedReader extends Reader   //BufferedReader 装饰者
{
	Reader reader;       //FileReader就是被装饰者
	
	BuffereReader(Reader reader)    //Reader reader = new FileReader();  父类型引用指向子类型对象
	{
		this.reader = reader;
	}
	
	//对FileReader中的close方法进行扩展
	public void close()
	{
		System.out.println("扩展代码1");
		reader.close();
		System.out.println("扩展代码2");
	}
}
  
public class Test02
{
	public static void main(String[] args)
	{
		/*
		//创建被装饰者
		FileReader fr = new FileReader();
		
		//创建装饰者
		BufferedReader br = new BufferedReader(fr);
		*/
		
		BufferedReader br = new BufferedReader(new FileReader());
		
		//通过执行装饰者中的方法间接去执行装饰着中的方法
		br.close();		
	}
}
  
  
====================================================================================================================================================
7.DataOutputStream
java.io.DataOutputStream;  根据字节输出流
可以将内存中的“int i = 10” 写入到硬盘文件中，写进去的不是字符串，写进去的是二进制数据，带类型

public class DataOutputStreamTest
{
	public static void main(String[] args) throw Exception
	{
		//创建数据字节输出流
		DataOutputStream dos = new DataOutputStream(new FileOutputStream("xxx"));
		
		byte b = 10;
		short s = 11;
		int i = 12;
		long l = 1000L;
		float f = 3.2f;
		double d = 2.3;
		boolean flag = false;
		char c = 'a';
		
		dos.writeByte(b);
		dos.writeShort(s);
		dos.writeInt(i);
		....
		
		
		dos.flush();
		dos.close();
	}
}
  
  
  
  
public class DataInputStreamTest
{
	public static void main(String[] args) throw Exception
	{
		DataInputStream dis = new DataInputStream(new FileInputStream(".."));
		
		//要使用该流读取数据，必须提前知道该文件中数据的存储格式，顺序
		//读的顺序必须跟写入的顺序一致
		
		byte b = dis.readByte();
		........
		
		dis.close();
    }
}

——————————————————————————————————————————————————————————————————————————————————————————————
import java.io.*;
public class Test01 
{
	public static void main(String[] args) throws Exception
	{
		DataOutputStream dos = new DataOutputStream(new FileOutputStream("temp01.txt"));
		DataInputStream dis = new DataInputStream(new FileInputStream("temp01.txt"));
		
		byte b = 98;
		char c = 'g';
		
		dos.writeByte(b);
		dos.writeChar(c);
		
		//System.out.print(new String(chars, 0, temp));
		//上面转化成String类型的原因就是为了能输出一段，而且String值可以接收byte和char类型
		System.out.println(dis.readByte());  //读取了之后就是byte char类型，继承Object类，自动调用toString
		System.out.println(dis.readChar());
		
		
		dos.flush();
		dos.close();
		dis.close();
	}
}



——————————————————————————————————————————————————————————————————————————————————————————————



  
===================================================================================================================================================
8.PrintStream
我觉得这个流就是依赖于System的，如果是输出到屏幕，就是PrintStream ps = System.out;
如果是输出到某个文件中，先使用System.setOut(new PrintStream(new FileOutputStream("log")));
再使用System.out.println("HAHA");就可以输送到某文件中
java.io.PrintStream;  标准输出流  默认打印到控制台  以字节方式
java.io.PrintWriter;  以字符的方式

public clas PrintStreamTest
{
	public static void main(String[] args) throws Exception
	{
		//默认是输出到控制台的
		System.out.println("HelloWorld");
		
		PrintStream ps = System.out;
		
		ps.println("JAVA...");
		
		//可以改变输出方向
		System.setOut(new PrintStream(new FileOutputStream("log")));
		
		//再次输出
		System.out.println("HAHA");
		
		//通常使用上面的这种方式记录日志
		//需求，记录日志，m1方法开始执行的时间和结束的时间，记录到log文件中
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS");
		System.out.println("m1方法开始执行" + sdf.format(new Date()));  //因为上面已经改变了输出方向
		m1();
		System.out.println("m1方法执行结束" + sdf.format(new Date()));
	}
	
	
	public static void m1()
	{
		System.out.println("m1 method excute");
	}
}

=======================================================================================================================================================
9.java.io.ObjectOutputStream    //序列化JAVA对象到硬盘  （Serial）
10.java.io.ObjectInputStream    //将硬盘中的数据反序列化到JVM内存   （DeSerial）
//序列化的意思就是：淘宝网如何保存购物车，就是将购物车里的数据序列化，切成一块一块，放到硬盘中，如果要对象要序列化，就得让类实现Serializable接口
//代表这个里面的对象是可以切成一块一块的，记得特殊待遇切成一块一块的内部表示就是分配一个序列号，只要这个类有一点改变，就会重新分配序列号，为了防止这种情况
//的发生，自配分配一个序列号
//反序列化，就是将硬盘中的数据拿出来

Compile 编译 （java-->class）
DeComplie 反编译  （class-->java）

public class ObjectOutputStreamTest
{
	public static void main(String[] args) throw Exception
	{
		User u1 = new User("刘德华");
		
		//创建输出流（序列化流）（JVM中的java对象状态保存到硬盘中）
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("xxx"));
		
		oos.writeObject(u1);
		
		oos.flush();
		oos.close();
	}
}


import java.io.Serializable;//该接口是一个可序列化的
							//该接口没有任何方法，是一个标志性的接口（标识接口）
							//像这样的接口：java.lang.Cloneable;  //可克隆的
							
/*
	表示接口的作用：起到表示的作用
	JVM如果看到该对象实现了某个标志接口会对他特殊待遇

*/
public class User implements Serializable
{
	String name;
	
	User(String name)
	{
		this.name = name;
	}
	
	public String toString()
	{
		return "User[name = "+name+"]";
	}
}


————————————————————————————————————————————————————————————————
反序列化
public class ObjectInputStreamTest01
{
	public static void main(String[] args) throws Exception
	{
		ObjectInputStream ois = new ObjectInputStream(new FilmInputStream("temp06"));
		
		Object o = ois.readOject();
		System.out.println(o);
		
		ois.close();
	}
}


=====================================================================================================================================================
public class Test{
	public static void main(String[] args)
	{
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("user.DBF"));
		
		User u = new User();
		oos.writeObject(u);
		
		oos.flush();
		oos.close();
	}
}


public class ObjectInputStreamTest01
{
	public static void main(String[] args) throws Exception
	{
		ObjectInputStream ois = new ObjectInputStream(new FilmInputStream("temp06"));
		
		Object o = ois.readOject();
		System.out.println(o);
		
		ois.close();
	}
}


//因为User实现了Serializable接口，JVM会特殊待遇，会给该类添加一个属性
//Static final long serialVerssionUID = .........;
//只要这个类一变，版本号就改变,

public class User implements Serializable
{
	
	//不让系统自动生成，自己写一个序列化版本号
	static final long serialVersionUID = 1231324434L;
	
	transient String name;   //如果不想让该属性参加序列化，需要使用transient关键字修饰，如果它不参加序列化，则最后结果为null
	
	User(String name)
	{
		this.name = name;
	}
	
	public String toString()
	{
		return "User[name = "+name+"]";
	}
}


=====================================================================================================================================================

/*
	java.io.File;
		1.File类和流无关，不能通过该类完成文件的读和写
		2.File是文件（它在啥地方）和目录路径名（在的地方+这个文件明）的抽象表示形式
	
	File代表的是硬盘上的Directory和file
	
	操！他是不是个傻逼，害得我写了半天
	File f1 = new File("c:/a/b/abc.txt");
	使用createNewFile()  就是如果路径不存在，就创建这个路径
	
	mkdir()   光创建文件夹，剩下啥也不创建
	
*/

public class Test01
{
	public static void main(String[] args) throws Exception
	{
		File f1 = new File("Test01.java");
		File f2 = new File("C:\\Users\\小可爱\\Documents\\MyJava\\javaProject\\Java-SE\\chapter-01\\Test01.java");
		
		System.out.println(f1.exitsts());  //true
		
		Film f4 = new File("C:/TT");
		
		//如果不存在创建
		if(!f4.exists())
		{
			//创建目录
			f4.mkdir();    //这个就是创建文件夹
			
			//创建文件
			f4.createNewFile();
		}
		
		File f5 = new File("c:/a/b/c/d/e/f");
		if(!f5.exists())
		{
			//创建多重目录
			f5.mkdirs();
		}
	}
}


=====================================================================================================================================================
public class Test02
{
	public static void main(String[] args)
	{
		File f1 = new File("Test02.java");
		
		//获取文件最后一次修改时间
		Date t = new Date(f1.lastModfied());
		System.out.println(new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss SSS").format(t));
		
		//列出子文件
		File f3 = new File("XXXXX");
		File[] fs = f3.listFiles();
		
		for(File f : fs)
		{
			System.out.println(f.getAbsolutePath());
		}
	}
}

=====================================================================================================================================================

//使用递归：找出某目录下所有的子目录以及子文件

public class Test03
{
	public static void main(String[] args)
	{
		File f = new File("D:/course");
		
		//调用方法完成查找
		method1(f);
	}
	
	public static void method1(File f)
	{
		if(f.isFile())
		{
			return;
		}
		
		//f有两种可能，f可能是文件，也可能是目录
		//先当作目录
		File[] fs = f.listFiles();
		
		for(File subF:fs)
		{
			System.out.println(subF.getAbsolutePath());
			method1(subF);
		}
	}
}
======================================================================================================================================
1.字符流的编码里面融合了编码表，中国字，日本字都可以自动去对应的表中进行查找
·中国人民通过对 ASCII 编码的中文扩充改造，产生了 GB2312 编码，可以表示6000多个常用汉字。
汉字实在是太多了，包括繁体和各种字符，于是产生了 GBK 编码，它包括了 GB2312 中的编码，
同时扩充了很多。 

·中国是个多民族国家，各个民族几乎都有自己独立的语言系统，为了表示那些字符，
继续把 GBK 编码扩充为 GB18030 编码。

·每个国家都像中国一样，把自己的语言编码，于是出现了各种各样的编码，如果你不安装相应的编码，
就无法解释相应编码想表达的内容。

·终于，有个叫 ISO 的组织看不下去了。他们一起创造了一种编码 UNICODE ，这种编码非常大，
大到可以容纳世界上任何一个文字和标志。所以只要电脑上有 UNICODE 这种编码系统，无论是全球哪种文字
只需要保存文件的时候，保存成 UNICODE 编码就可以被其他电脑正常解释。

·UNICODE 在网络传输中，出现了两个标准 UTF-8 和 UTF-16，分别每次传输 8个位和 16个位。
于是就会有人产生疑问，UTF-8 既然能保存那么多文字、符号，为什么国内还有这么多使用 GBK 等编码的人？
因为 UTF-8 等编码体积比较大，占电脑空间比较多，如果面向的使用人群绝大部分都是中国人，用 GBK 等编码也可以。

2.通用字节流
3.分为字符流和字节流
4.FileWriter  后缀名是父类名，前缀名是该对象的功能

1.FileWriter
	凡是能和设备上数据发生数据关系的，能去处理的，都会发生IO异常，无论读还是写
	Java虚拟机去调用windows操作系统中的write方法，往windows操作系统内部写数据，所以就和设备上数据发生了数据关系

	//创建一个FileWriter对象，该对象一被初始化就必须要明确被操作的文件
	//而且该文件会被创建到指定目录下，如果该目录下已有同名文件将被覆盖
	//其实该步就是在明确数据将要存放的目的地
	FileWriter fw = new FileWirter("demo.txt");
	
	//调用write方法，将字符串写入到流中，就是在水管中，还没有去到池子里
	fw.write("ahduia");

	//刷新流对象中的缓冲中的数据
	//将数据刷新到目的地中，就是把水管里的弄到池子里
	//fw.flush();
	
	//关闭流资源，但是在关闭之前会进行flush
	fw.close();
	
	——————————————————————————————————————
	windows当中的记事本中想要输入换行（fw.write("hello\r\nworld")）
	如果是想在Notepad++中输入换行（fw.write("hello\nworld")）
	——————————————————————————————————————
	
2.FileReader and BufferedWriter
	//创建一个文件读取流对象，和指定名称的文件想关联
	//要保证该文件是存在的，如果不存在，会发生异常FileNotFoundException
	FlieReader fr = new FileReader("demo.txt");
	
	//调用读取流对象的read方法
	//read();一次读一个字符，而且会自动往下读
	
	int ch = 0;
	While(ch = fr.read() != -1)    //如果是读取一个字符，返回的值是字符所对应的unicode码
	                               //如果读取的是数组，返回的是成功读取个数
	{
		System.out.println("(char)ch");
	}
	
	/*
		硬盘的容量非常的大，速度一般，而且可以实现永久存储，电脑程序就存在那里。
        内存是容量比较小，速度快，是CPU工作的地方，对系统性能影响很大，CPU工作的时候就会把硬盘中要运行的程序先调到内存中才能处理。
        缓存的容量最小，但速度最快，为了协调CPU的高速度和内存的相对低速度的缓冲区域，形象的说就和高楼上水塔一样。	
	*/
	
	实现读操作：
	我估计有三个指针：硬盘读操作的指针，数组指针，缓冲区指针
	
			内存————————————————————————————————————————————>缓冲区——————————————————————————————————————————————>硬盘
内存中有缓冲区，缓冲区就是队列，新数据放在          				 					将硬盘中的数据拿一个放到内存中，也可以拿一组，放到内存中
队列末尾，而之前的char byte数组，就是内存									 			显然拿一组放到硬盘中效率更高
中的数组

只有用到缓冲区，才需要要flush(),因为reader是读取字符，所以得把一个字节暂时存储在缓冲区中，再读取一个字节之后，才可以拼
成一个字，flush是清除缓冲区中的内容，如果是Stream，不需要刷新，因为最小操作单位就是字节

对于输出流来说，我觉得先通过硬盘读取到一个字节的数据，然后经过电线把这一个字节的数据传到内存中，也就是所谓的读一个，传一个，而如果是使用
数组，就是读一组，传一组，如果是使用Bufferd就是全读，一起传，从硬盘中中读取到的数据暂时存储在随机存取存储器中，看要求进行电子传输

输出流我觉得是一种电流，当这个电线里面的电子满了，就输出到指定位置了，flush()的主要目的，就是把电线里面还没来得及过去的电子弄到文件里
	
如果是使用BufferWriter，就是在底层构建了一个StringBuffer数组，可以自动扩容，就是把你之前写的自定义数组char[] nu = char[3];之类进行封装，
变成一个更加高级的可以扩容的数组，这时，只需要从硬盘中一次性填充数组，一次性放到内存就可以，如果你写的，得反复多次，还掌握不好数组的长度
它是不是很强大呢？
注意：BufferWriter中还有一个newLine方法，因为在windows系统中和Linux系统中换行操作不同一个是\r\n，另一个是\n，所以newLine容纳了系统之间的差异性
	  write()方法写入的是一行中的有效数据，而换行符\n，回车\r之类没有往回返，所以要在之后加newLine
	  
      ——————————————————————————————————————————————————————————————————————————
      例如：
	  FileWriter fw = new FileWriter("buf.txt");
	  BufferWriter bufw = new BufferedWriter(fw);
	  
	  for(int x = 1; x < 5; x++)
	  {
		  //现往内存中输入一个"abcd" + x \n
		  bufw.write("abcd" + x);
		  bufw.newLine();
		  
		  //将内存中的数据输入到目标文件中bufw，防止突然断电，内存中的东西全没了
		  bufw.flush();
	  }
	  ——————————————————————————————————————————————————————————————————————————
	  
	
	例如：
	FileWriter fw = new FileWriter("RuntimeDemo_copy.txt");  //写到哪里
	
	FileReader fr = new FileReader("RuntimeDemo.java");    //重哪里读
	
	int ch = 0;
	
	while((ch = fr.read()) != -1)
	{
		fw.write(ch);   //这个步骤完成之后，水就全去水管里了
	}
	
	fw.close();
	fr.close();
	
3.BufferedReader	
同理：将读取到的数据放入到BufferesReader内存中
接下来解决如何读：

int read() 
读一个字符  

int read(char[] cbuf, int off, int len) 
将字符读入数组的一部分。 
 
//readLine方法的原理
//无论是读一行，获取读取多个字符。其实最终都是在硬盘上一个一个读取。所以最终使用的还是read方法一次读一个的方法
//所以最终使用的还是read方法一次读一个的方法，readLine方法的出现是增强read方法的功能，其实就是将被增强的对象传给一个增强类
String readLine()  //文本是以行的形式存在的  如果读到末尾，返回null
读一行文字。  

——————————————————————————————————————————————————————————————————————————
1.模拟实现BufferedReader方法
FileReader fr = new FileReader("buf.txt");
BufferedReader bufr = new BufferedReader(fr);

class MyBudderedReader
{
	private FileReader r;
	
	MyBudderedReader(FileReader r)
	{
		this.r = r;
	}
		
	//可以一次读一行的方法
	public String myReadLine()
	{
		//这个毕竟只是模拟BufferedReader，实际上我觉得内部肯定是输入到随机存取存储器，而这个是读一个，输到内存中，还是有出入的
		StringBuilder sb = new StringBuilder();
		int ch = 0;
		while((ch = r.read()) != -1)
		{
			if(ch == '\r')
				continue;
			if(ch == '\n')
				return sb.toString();
			else
				sb.append((char)ch);
		}
		
		if(sb.length() != 0)             //如果说最后一行没有换行符，就会使得最后一行输不出去，这个是为了保证最后一行肯定输出去
			return sb.toString();
			
		return null;
	}
	
	//缓冲区内部就把fr关闭掉了
	public void myClose()
	{
		r.close();
	}
}

2.模拟实现LineNumberReader方法 就是比BufferedReader多在它之前加了行号
class MyLineNumberReader extends MyBufferReader
{
	private int LineNumber;
	
	MyLineNumberReader(Reader r)
	{
		super(r);
	}
	
	public String MyReadLine() throw TOException
	{
		LineNumer++;
		return super.myReadLine();
	}
	
	public void setLineNumber(int LineNumber)
	{
		this.LineNumber = LineNumber;
	}
	
	public int getLineNumber()
	{
		return LineNumber;
	}
}

接下来解决：将读到的东西放到哪里，是找个变量存起来，还是找个文件存起来
	
——————————————————————————————————————————————————————————————————————————
Java中String，StringBuilder和StringBuffer的区别
运算速度比较
StringBuilder > StringBuffer > String
String 底层是通过不断创建新的String对象实现原有String对象的增加，将原来的String对象用垃圾回收器回收
       所以在字符串需要增加时并不适合

String：适用于少量的字符串操作。
StringBuilder：适用于单线程下在字符串缓冲区进行大量操作。
StringBuffer：适用于多线程下在字符串缓冲区进行大量操作。

————————————————————————————————————————————————————————————————————————————————

4.装饰者模式
如何解释BufferedReader的装饰者模式
BufferedReader和FileReader都实现了 Reader接口，这个接口中只有一个类就是read，意思就是只要实现这个接口，就得是现在这个接口中的方法
而这个方法时单字符读取，每一个实现这个接口的子类所对应的read的意思是：read当前流中的一个字符

如果BufferedReader要对一个FileReader进行装饰，就是对FileReader的读取方法进行改变，所以必须知道这个流，使用接口Reader，可以使这两个类完全分离
应用多态，将这个流传入BufferedReader中，对reader方式改变     而BufferedReader中的read实际上没有用，就是还是读取一个字符，并没有体现出优势
	
	
例如：
MyReader  //专门用于读取数据的类
	——MyTextReader
	——MyMediaReader
	——MyDataReader 
	——MyBufferReader
装饰者因为增强已有对象，具备的功能和已有的是相同的，只不过提供了更强的功能
所以装饰类和被装饰类都是属于一个体系中的	
	
	
5.InputStream
在InputStream中有一个available方法，可以计算出这个文档中有多少字，\r\n算两个字，如果说数据太大，慎用，数据不是太大，可以使用
还是byte[] buf = new byte[1024];  //定义1024的整数倍是最合适的

6.BufferedInputStream
class MyBufferedInputStream
{
	private InputStream in;
	private byte[] buf = new byte[1024];
	private int pos = 0, count = 0;
	
	MyBufferedInputStream(InputSream in)
	{
		this.in = in;
	}
	
	/*
		如果是读取音频，视频字节如何读取，如果是这样的话，就不想读取文本有优势，读取文本可以一行一行读取，通过换行符来提高效率，而读取音频根本无
		换行符可言，所以只能先读到一个数组中，把这个数组通过流传入到内存中，因为read()方法只是读取一个字节，所以把内存中的内容一个一个读
	*/
	public int myRead() throws IOException
	{
		if(count == 0)
		{
			//pos是应该读哪个，count是还剩几个可以读
			count = in.read(buf);
			if(count < 0)
				return -1;
			pos = 0;
			byte b = buf[pos];
			
			count--;
			pos++;
			/*
				如果读取到的是1111 1111（-1），变成int类型会自动在前面补1，还是-1，但我想让它不是-1，如果是-1的话，就hi和下面while循环产生冲突，
				如果保留前面8个，b & 255（前八个全是1）, 如果保留前面4个，b & 15（前四个全是1）
			*/
			return b & 0xff;//255的16进制
		}
		else if(count > 0)
		{
			byte b = buf[pos];
			
			count--;
			pos++;
			return b;
		}
		return -1;
	}
	
	public void myClose() throws IOException
	{
		in.close();
	}
	
}
	
	
public static void copy_2() throws IOException
{
	MyBufferedInputStream bufis = new MyBufferedInputStream(new FileInputStream("c:\\0.mp3"));
	BufferedOutputStream bufos = new BufferedOutputStream(new FileOutputStream("c:\\2.mp3"));
	
	int by = 0;
	
	while(by = bufis.myRead() != -1)
	{
		bufos.write(by);  //write的目的就是强转，把前八位取出来
	}
	
	bufos.close();
	bufis.myClose();
}	
	
	
7.获取键盘录入（就是把之前的硬盘改成了键盘）
System.out;  对应的是标准的输出设备，控制台
System.in;   对应的标准输入设备，键盘	
	
InputStream in = System.in;
int by1 = in.read();   //read()  方法返回int类型

while((ch = in.read()) != -1)   如果想结束这个循环，在键盘上录入ctrl + c
{
	System.out.println(ch);
}
	
——————————————————————————————————————————————————————————————————————————
当录入一行数据后，就将该行数据进行打印
如果录入的是over,那么停止录入

import java.io.*;
public class ReadIn
{
	InputStream in = System.in;
	StringBuffer sb = new StringBuffer();
	
	while(true)
	{
		int ch = in.read();
		
		if(ch == '\r')
		{
			continue;
		}
		if(ch == '\n')
		{
			String s = sb.toString();
			if("over".equals(s))
			{
				break;
			}
			
			System.out.println(s.toUpperCase());  //返回大写
			sb.delete(0,sb.length());
		}
		
		sb.append((char)ch);
	}
}	
	
	
	
结论：就是之前读一行代码原理 readLine

8.各个类中特有的方法
FilmInputStream     available()
FilmOutputStream
FilmReader
FilmWriter

带有缓冲区的四个流
BufferedReader		 String readLine();    构造方法:Reader 也就是实现这个接口的都可以，多态
BufferedWriter       newLine()             构造方法：Writer
BufferedInputStream     available()   读取字节数的估计值
BufferedOutputStream    

DataInputStream
DataOutputStream

ObjectInputStream
ObjectOutputStream

//转换流（字节流转换成字符流）
/*
	InputStreamReader(InputStream in, CharsetDecoder dec) 
   创建一个使用给定字符集解码器的InputStreamReader
	
	就是指定的表，把字节转换成字符(nnn   , "UTF-8")
	
	InputStreamReader（采用指定编码表将字节转换成字符）的直接子类就是FilmReader（采用默认编码表将将字节转换成字符，把它封装成一个类）
*/
InputStreamReader
OutputSteamWriter

PrintWriter   System.out是系统默认提供的PrintStream，表示标准输出；可以PrintWriter.print/println
PrintStream   
PrintStream在遇到换行符的时候就会自动刷新，即在调用了println()方法，或者文本中出现“\n”,就会自动flush
          PrintWriter则不会，要在构造方法中设置自动刷新，或者手动flush。
	
___________________________

System
static InputStream in 
“标准”输入流。
  
static PrintStream out 
“标准”输出流。  

static void setIn(InputStream in) 
重新分配“标准”输入流。
System.setIn(new FileInputStream("PersonDemo.java"));
  
static void setOut(PrintStream out) 
重新分配“标准”输出流。  
System.setOut(new PrintStream("zzz.txt"));

9.如何选择流：通过两个明确来完成
——明确源和目的
  源：    输入流  InputStream   Reader
  目的：  输出流  OutputSream   Writer
 
——操作的数据是否是纯文本
  是：  字符流
  不是：字节流

——当体系明确后，再明确要使用哪个具体的对象
  通过设备来区分：
  源设备：   内存  硬盘  键盘
  目的设备： 内存  硬盘  控制台


10.如何将错误信息打印到指定文件中，并附上日期
class Exception
{
	public static void main(String[] args) throws IOException
	{
		try
		{
			int[] arr = new int[2];
			System.out.println(arr[3]);
		}
		catch(Exception e)
		{
			try
			{
				Data d = new Data();
				SimpleDateFormat sdf = new SimpleDataFormat("yyyy-mm-dd hh:mm:ss");
				String s = sdf.format(d);
				
				printStream ps = new PrintStream("XXXX");  //重新改变流的输出方向
				ps.println(s);
				System.setOut(ps);   //重新分配输出流,可以把输出设备改掉
			}
			catch(IOException ex)
			{
				throw new RuntimeException("日志文件异常");
			}
			
			//也可以把上面的都不用写，直接写e.printStackTrace(new PrintStream("a.txt"));
			e.printStackTrace(System.out);
		}
	}
}


public void printStackTrace(PrintStream s)将此throwable和其追溯打印到指定的打印流。 System.out的类型就是PrintStream


11.系统信息
Properties prop = System.getPropertise();

//System.out.println(prop);
prop.list(new PrintStream("sysinfo.txt"));


12.File类
流只能操作数据，要对文件进行处理，只能用流

public static void cons
{
	File f1 = new File("a.txt");
	
	File f2 = new File("c:\\abc","b.txt");
	
	//输入啥，打出来就是啥
	sop(f1);   //打印出来的就是a.txt
	sop(f2);   //c:\abc\b.txt;  
	
	File f2 = new File("c:" + File.separator + "abc" + File.separator + "a.txt");  //可以把\换成 File.separator，这个就相当于分隔符的意思
}

/*
File类的常见方法
1.创建
  boolean CreateNewFile();
  boolean mkdir();  //创建文件夹
  boolean mkdirs();  //创建多级文件夹
  
2.删除
  boolean delete()   //删除失败返回false，如果文件正在使用，则删除不了返回false
 删除由此抽象路径名表示的文件或目录。 
 
 void deleteOnExit()   //如果一个文件正在执行，是删不掉的，因为i如果想删一个正在执行的文件，系统会报提示，所以手动删除是删不掉的；再程序退出时删除指定对象
 请求在虚拟机终止时删除由此抽象路径名表示的文件或目录。 

3.判断
 Boolean exists();  //文件是否存在
 isFile();
 isDirectory();
 isHidden();
 isAbsolute();
 
4.获取信息
File getAbsoluteFile()     //这个和下面的区别就是，这个把File封装成一个对象，下面只是饭hi一个字符串
返回此抽象路径名的绝对形式。  
String getAbsolutePath() 
返回此抽象路径名的绝对路径名字符串。
  
 
String getName() 
返回由此抽象路径名表示的文件或目录的名称。  
String getParent() 
返回此抽象路径名的父 null的路径名字符串，如果此路径名未命名为父目录，则返回null。  
File getParentFile() 
返回此抽象路径名的父，或抽象路径名 null如果此路径名没有指定父目录。  
String getPath() 
将此抽象路径名转换为路径名字符串。    

*/


File f = new File("file.txt");   //创建实例对象

//创建一个文件
sop("create:" + f.createNewFile());  //这个只是为了打印看出来  如果创建成功true，创建失败false 
                                     //和输出流不一样，输出流对象一建立创建文件，而且文件已经存在，会覆盖

mkdir只能创建一级目录，不能创建多级目录   
mkdir创建多级文件夹

———————————————————————————————————————— 
File f = new File("file.txt");

//记住在判断文件对象是否是文件或者目的时，必须先判断该文件对象封装的内容是否存在
//通过exists判断
sop(f.idDirectory());
sop(f.isFile());

——————————————————————————————————————
获取路径的时候，可以只创建对象
File f = new File("file.txt");

sop("path:" + f.getPath());
sop(f.getAbsolutePath());，
sop(f.getParent());    //返回false，如果没有指定父目录，它的父目录就是在变化的，如果获取的时相对路径，饭回空


————————————————————————————————————————

length表示文件的长度，因为返回值时long类型，所以储存数据的范围要比available大

——————————————————————————————————————————
改文件的名字
File f1 = new File("ta.java");
File f2 = new File("ming.java");
f1.renameTo(f2);

——————————————————————————————————————————
File[] files = File.listRoots();   //获取当前系统中的有效盘  C  D..
	
——————————————————————————————————————————

File f = new File("c:\\");//我感觉这个就相当于文件流，可以用来指定到这个对象,createNewFile的目的主要是在指定的路径中创造这个文件，方法还是File的方法
String[] names = f.list();  /打印当前路径下的所有文件和名称，包含隐藏文件，改目录必须存在
for(String name : names)
{
	System.out.println(name);
}

——————————————————————————————————————————
在当前目录下选出指定的文件
File dir = new File("d:\\java1223\\day18");

//String[] list(FilenameFilter filter)   去找FilenameFilter，发现是一个接口，接口里面只有一个类，就是accept，实现匿名内部类
//返回一个字符串数组，命名由此抽象路径名表示的目录中满足指定过滤器的文件和目录。  
String[] arr = dir.list(new FilenameFilter())   //保存的数组
{
	public boolean accept(File dir, String name)  //File是目录   name是文件的名字
	{
		return name.endsWith(".bmp");
	}	
}
)
	
-------------------------------------------
listFiles  返回的是文件对象，比上面好一点
File dir = new File("d:\\java1223\\day18");
File[] files = dir.listFiles();

for(File f : files)
{
	System.out.println(f.getName() + "::" + f.length());
}
	
	
——————————————————————————————————————————————————————————————————————————
把当前路径下所有的文件全数出来，包括文件夹中的文件
递归
class FileDemo
{
	public static void main(String[] srgs)
	{
		File dir = new File("d:\\java1223");
		showDir(dir);
	}
	public static String getLevel(int level)
	{
		StringBuilder sb = new StringBuilder();
		
		for(int x = 0; x < level; x++)
		{
			sb.append("|————");
		}
	}
	
	public static void showDir(File dir)
	{
		System.out.println(getLevel(level) + dir.getName());
		
		level++;
		File[] files = dir.listFiles();
		
		for(int x = 0; i < files.length; x++)
		{
			if(files[x].isDirectory())
				showDir(files[x],level);
			else
				System.out.println(getLevel(level) + files[x]);
		}
	}
}

——————————————————————————————————————————————————————————————————————————
//删除一个带内容的目录
//删除原理
//在windows中，删除目录是从里面往外删除的
//既然是从里往外删除，就要用递归

class remove
{
	public satic void main(String[] args)
	{
		File dir = new File("d:\\testdir");
		removeDir(dir);
	}
	
	public static void removeDir(File dir)
	{
		File[] files = dir.listFiles();
		
		for(int x = 0; X < files.length; x++)
		{
			if(files[x].isDirectory())
				removeDir(files[x]);
			else
				files[x].delete();
		}
		dir.delete();
	}
}	
	
	
——————————————————————————————————————————————————————————————————————————
/*
	将一个指定目录下的java文件的绝对路径，存储到一个文本文件中，建立一个java文件列表文件
	1.对指定目录进行递归
	2.获取递归过程中所有的java文件的路径
	3.将这些路径存储到集合中
	4.将这些几何数据写入到一个文件中
*/	
	

public static void main(String[] args)
{
	File dir = new File("d:\\java1223");
	List<File> list = new ArrayList<File>();
	fileToList(dir,List<File> list);
	
	File file = new File(dir, "javalist.txt");
	writeToFile(list, file.toString());
}
	

public static void fileToList(File dir, List<File> list)
{
	File[] files = dir.listFiles();
	
	for(File file : files)
	{
		if(file.isDirectory())
			fileToList(file,list);
		else
		{
			if(file.getName.endWith(".java"))
				list.add(file);
		}
	}
}
	
	
	
	
public static void writeToFile(List<File> list, String javaListFile)
{
	BufferedWrite bufw = null;
	try
	{
		bufw = new BufferedWriter(new FileWriter(javaListFile));
		
		for(File f : list)
		{
			String path = f.getAbsolutePath();
			bufw.write(path);
			bufw.newLine();
			bufw.flush();
		}
	}
	
	catch (IOException e)
	{
		throw e;
	}
	
	finally
	{
		try
		{
			if(bufw != null)
			{
				bufw.close();
			}
		}
		
		catch(IOException e)
			throw e;
	}
}	
	
——————————————————————————————————————————————————————————————————————————
Propertises是hashtable的子类
也就是说它具备map集合的特点，而且它里面储存的简直对都是字符串
是集合中IO技术相结合的集合容器
该对象的特点：可以用于键值对形式的配置文件

class PropertiesDemo
{
	public static void main(String[] args)
	{
		
	}
	
	
	public static void loadDEmo() throws IOException
	{
		Propertise prop = new Properties();
		FileInputStream fis = new FileInputStream("info.txt");
		
		//将流中的数据加载进集合
		prop.load(fis);
		
		//如何修改数据
		prop.setProperty("wangwu","39");   //实现覆盖，但是这个只是将propertise中的覆盖，原来文件中的没有改变，如果想改变，使用store
		——————————————————————————————————————
		FileOutputStream fos = new FileOutputStream("info.txt");
		prop.store(fos,"hha");  //后面这个是可以把注释写进去，可有可无
		————————————————————————————————————————
		
		System.out.println(prop);
		
		prop.list(System.out);   //输出到控制台
	}
	
	//如何将集合中的数据存储到propertise,原理
	public static void method_1() throw IOException
	{
		BufferedReader bufr = new BufferedReader(new FileReader("info.txt"));
		
		String line = null;
		Propertise prop = new Propertise();
		
		while((line = bufr.readLine()) != null)
		{
			String[] arr = line.split("=");
			prop.setProperty(arr[0], arr[1]);
		}
		
		bufr.close();
		
		System.out.println(prop);
	}
	
	//设置和获取元素
	public static void setAndGet()
	{
		Propertise prop = new Propertise();
		
		prop.setProperty("zhangsan", "30");
		prop.setProperty("lisi", "39");
		Set<String> names = prop.stringPropertyName();
		for(String s : names)
		{
			System.out.println(s + ":" + prop.getProperty(s));
		}
	}
	
}	
	
____________________________________________________________
/*
	用于记录应用程序的运行次数
	如果使用次数已到，那么输出注册提示
	如果使用循环，那么在再次加载进到这个文件中，这个变量又会被重新初始化为0
	所以需要一个文件永久保存有关这个用户的数据，使它再次进入时，先加载这个数据
	以键值对储存变量名和值
	
	键值对是map集合
	数据是以文件形式储存，使用io技术
	map + io-->propreties
*/

class RunCount
{
	public static void main(String[] args)
	{
		Propertise prop = new Propertise();
		File file = new File("count.ini");  //如果这个文件已经存在，目的就是把这个文件包装成可以处理的对象
		if(!file.exists())
			file.createNewFile();
		FileInputStream fis = new File("count.ini");
		
		prop.load(fis);
		
		int count = 0;
		String value = prop.getProperty("time");
		
		if(value != null)
		{
			count = Integer.parseInt(value);
			if(count >= 5)
			{
				System.out.println("您好，使用次数已到，拿钱");
				return;
			}
		}
		
		
		//因为要查看的是一个变量的当前值
		if(value != null)
			count = Integer.parseInt(value);
			
		count++;
		prop.setProperty("time", count + "");
		FileOutSream fos = new FileOutputSream(file);
		
		prop.store(fos, "");
		
		fos.close();
		fis.close();
	}
}
	
——————————————————————————————————————————————————————————————————
PrintStream是OutputStream的间接子类，所以有写的方法，但只能写字节
PrintStream强大在有println和print

构造函数可以接收的参数类型：
1.file对象：file
2.字符串路径：String
3.字节输出流：OutputStream

字符打印流：
PrintWriter
构造函数可以接收的参数类型：
1.file对象：file
2.字符串路径：String
3.字节输出流：OutputStream
4.字符输出流：writer

/*
public PrintWriter(OutputStream out,
           boolean autoFlush)从现有的OutputStream创建一个新的PrintWriter。 这个方便的构造函数创建必要的中间OutputStreamWriter，它将使用默认字符编码将字符转换为字节。 
参数 
out - 输出流 
autoFlush - 一个布尔值 如果真的话 ， println，printf或format方法将刷新输出缓冲区 

*/
	
public static void main(String[] args) throws IOException
{
	//这里的System.in   System.out就相当于文件，只不过这个文件时键盘和屏幕
	BuffereReader bufr = new BufferedReader(new InputStreamReader(System.in));
	
	                                 //只有这个形式，才可以实现自动刷新 前面必须是outputStream类型
	PrintWriter out = new PrintWriter(new FileWriter("s.txt"),true);   //true表示清空缓冲区
	
	String line = null;
	
	while((line = bufr.readLine()) != null)
	{
		if("over".equals(line))
			break;
		out.println(line.toUpperCase());
	}
	
	out.close();
	bufr.close();
}	

——————————————————————————————————————————————————————————————————————————————————————————————————————————
	
SequenceInputStream流
就是把多个流首尾相接，连成一个流，进行读取
因为要连接

SequenceInputStream(Enumeration<? extends InputStream> e)    //可以传多个流的初始化
初始化新创建 SequenceInputStream通过记住参数，
它必须是一个 Enumeration产生对象，它们的运行时类型是 InputStream 。 

public interface Enumeration<E>
实现枚举接口的对象生成一系列元素，一次一个。 连续调用nextElement方法返回系列的连续元素。

Enumeration<E> elements() 
返回此向量的组件的枚举。   
public static void main(String[] args) throws IOException
{
	Vector<FileInputStream> v = new Vector<FileInputStream>();
	
	v.add(new FileInputStream("c:\\1.txt"));
	v.add(new FileInputStream("c:\\2.txt"));
	v.add(new FileInputStream("c:\\3.txt"));
	
	Enumeration<FileInputStream> en = V.elements();
	SequenceInputStream sis = new SequenceInputStream(en);
	FileOutputStream fos = new FileOutputStream("c:\\4.txt");
	
	byte[] buf = new byte[1024];
	
	int len = 0;
	while((len = sis.read(buf)) != -1)
	{
		fos.write(buf, 0, len);
	}
	
	fos.close();
	sis.close();
}
	
——————————————————————————————————————————————————————————————————————————
//把一个文件切成好几段储存
public static void splitFile() throws IOException
{
	FileInputStream fis = new FileInputStream("c:\\1.bmp");
	FileOutputStream fos = null;
	
	byte[] buf = new byte[1024 * 1024];
	
	int len = 0;
	int count = 1;
	while((len = fis.read(buf)) != -1)
	{
		fos == new FileOutputSream("c:\\splitfiles\\" + (count++) + ".part");
		fos.write(buf,0,len);
		fos.close();
	}
	
	fis.close();
}	


——————————————————————————————————————————————————————————————————————————————————————————————————————————
管道流
class Read implements Runnanle
{
	private PipedInputStream in;
	Read(PipedInputStream in)
	{
		this.in = in;
	}
	
	public void run()
	{
		try
		{
			byte[] buf = new byte[1024];
			int len = in.read(buf);   //必须有数据，才能读取
			
			String s = new String(buf, 0, len);
			System.out.println(s);
			in.close();
		}
		catch(IOException e)
		{
			throw new RuntimeException("管道读取流失败");
		}
	}
}	

	
class Write implements Runnable
{
	private PipedOutputStream out;
	Write(PipedOutputStream out)
	{
		this out = out;
	}
	
	public void run()
	{
		try
		{
			out.write("piped 来了".getByte());
			put.close();
		}
		catch(IOException e)
		{
			throw new RuntimeException("管道输出流失败");
		}
	}
}
	
class PipedStreamDemo
{
	public static void main(String[] args) throws IOException
	{
		PipedInputStream in = new PipedInputStream();
		PipedOutputStream out = new PipedOutputStream();
		in.connect(out);
		
		Read r = new Read(in);
		Write w = new Write(out);
		
		//建立两个线程，下面这两个线程谁先抢到算谁
		new Thread(r).start();
		new Thread(w).start();
	}
}
	
——————————————————————————————————————————————————————————————————————————
RandomAcessFile 
/*
	RandomAccessFile
	该类不是算是IO体系中子类
	而是直接继承Object

	但是它是IO包中成员，因为它具备读和写功能
	内部封装了一个数组，而且通过指针对数组的元素进行操作
	可以通过getFilePointer获取指针位置
	同时可以通过seek改变指针的位置
	
	其实完成读写的原理就是内部封装了字节输入流和输出流
	
	通过构造函数可以看出，该类只能操作文件
	而且操作文件还有模式：只读 r  读写rw等
	如果模式为r，不会创建文件，会去读取一个已存在文件，如果该文件不存在，则会出现异常
	如果模式为rw，操作的文件不存在，会自动创建，如果存在则不会覆盖
	
	而且该对象的构造函数要操作的文件不存在，会自动创建，如果存在会不会覆盖
	
	可以实现数据的分段写入  多线程分段写入  下载软件原理  多线程下载
*/
	
class RandomAccessFileDemo
{
	public static void main(String[] args)
	{
		
	}
	
	public static void readFile()
	{
		RandomAccessFile raf = new RandomAccessFile("ran.txt","r");  //底层是以数组的形式存储的
		/*
				李    四            a    王    五                 c
		       0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
		*/
		
		//调整对象中的指针
		//raf.seek(8 * 1);  //移动到王那里
		//跳过指定的字节数
		//可以往下跳，不能忘回跳
		raf.skipBytes(8);
		
		byte[] buf = new byte[4];  //一次读取四个字节
		raf.read(buf);
		String name = new String(buf);
		
		int age = raf.readInt();   //有一个可以直接读取四个字节的方法
			
		
	}
	
	public static vodi writeFile_2() throws IOException
	{
		RandomAccessFile raf = new RandomAccessFile("ran.txt", "rw");
		
		raf.write(8 * 3);   //如果是raf.write(0);  可以把第一个位置覆盖
		
		raf.write("周期".getBytes());
		raf.writeInt(103);
		
		raf.close();
	}
	
	
	public static void writeFile()
	{
		RandomAccessFile raf = new RandomAccessFile("ran.txt", "rw");
		
		raf.write("李四".getBytes());
		
		//writeInt 按四个字节将int写入该文件，先写高字节
		//raf.write(97);   //write只写数字转化成二进制的最低八位
		raf.writeInt(389);
		
		raf.close();
	}
}	
	
——————————————————————————————————————————————————————————————————————————————————————————————————————————
以内存为源的操作
操作字符数组
CharArrayReader CharArrayWriter

操作字符串
StringReader 和 StringWriter

操作字节数组
ByteArrayInputStream ByteArrayOutputStream
操作字节数组
/*
	用于操作字节数组的流对象
	ByteArrayInputStream ：在构造的时候，需要接受数据源，而且数据源是一个字节数组

	ByteArrayOutputStream : 在构造的时候，不用定义数据目的，因为该对象中已经内部封装了可变长度的字节数组，这个就是数据目的地
	
	因为这两个流对象都操作的数组，并没有使用系统资源
	所以，不用close关闭
	
	在流操作规律讲解时：
	源设备：
		键盘 System.in     硬盘 FileStream     内存 ArrayStream
	目的设备
		控制台 System.out      硬盘FileStream      内存ArrayStream
*/

//其两个流就是两个内存里的一个数组实现读和写，只不过这个数组的长度是可变的
class ByteArrayStream
{
	public static void main(String[] args)
	{
		//数据源
		ByteArrayInputStream bis = new ByteArrayInputStream("ABCDEFG".getBytes());
		
		//数据目的
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		
		int by = 0;
		while((by = bis.read())) != -1)
		{
			bos.write(by);
		}
		Systemout.println(bos.size()); 

		//把数组里的东西一次性写到一个文件中
		bos.writeTO(new FileOutputStream("a.txt"));
	}
}
	
——————————————————————————————————————————————————————————————————————————————————————————————————————————
不同的码
class EncodeStream
{
	public static void main(String[] args) throws IOException
	{
		//writeText();
		readText();
	}
	
	public static void readText() throws IOException
	{
		InputStreamReader isr = new InputStreamReader(new FileInputStream("gbk.txt"),"UTF-8");
		char[] buf = new char[10];
		int len = isr.read(buf);
		
		String str = new String(buf,0,len);
		
		System.out.println(str);
		
		isr.close();
	}
	
	public static void writeText() throws IOExcepion
	{
		OutStreamWriter osw = new OutputStreamWriter(new FileOutStream("utf.txt"),"UTF-8");
		osw.write("你好");
		ows.close();
	}
}
	
//你用什么码编的程序，就必须用什么码解
//在utf-8中，一个汉字占3个字节               在bgk中，一个汉字占两个字节

假如输入汉字“你好”
utf-8：你 -12 -45 -99              好  -77 -55 -46
gbk  ：你 -17 -55                  好  -24 -15

如果用gbk编码去查utf-8： -17 -55 -24用这三个字节去查utf-8没找见，所以是？    再用-15去查utf-8没找见，所以是？
如果用utf-8编码去查gbk： 先用-12 -45 去查gbk，传回一个乱七八糟的字   -99 -77 去查gbk，传回一个乱七八糟的字   -55 -46去查gbk，传回一个乱七八糟的字

==================================================================================================================================================================
多线程|
======
java.lang.Thread
1.继承Thread
Thread t = new Prosessor();
t.start();

2.实现Runnable接口
Thread t = new Thread(new Processor());
t.start();

3.获取线程的名字
(1)形式参数法 
name可以当作形式参数传进去
Test(String name)
{
	super(name);
}

this.getName();

(2)类函数法
在哪个线程里，输出的就是哪个线程里的名字
Thread t = Thread.currentThread();
t.getName();

(3)给线程起名字
在要起名字的线程外边给线程起名字
Thread t1 = new Thread(new Processer());
t1.setName("t1");
t1.start();

4.设置线程的优先级
这一步写在start();之前
t.setPriority(1);
t.setPriority(5);

5.让当前线程阻塞
(1)sleep写在哪个里面就是让哪个线程阻塞，跟调用者无关
   因为是静态方法
try
{
	Thread.sleep(1000);   //让当前线程阻塞1s
}
catch(InterruptedException e)
{
	e.printStackTrace();
}

(2)打断线程的休眠
t.interrupt();

6.阻塞当前线程，但是让位时间不固定
Thread.yield()   //静态方法


7.线程的合并
//让t线程和出现在哪个线程中的线程合并
t.join();


8.线程的同步
(1)锁本体（对象）
Object obj = new Object();

(2)同步代码块
里面是需要同步的代码块
synchronized(obj)
{
	
}

(3)同步函数
静态的同步方法，使用的锁是该方法所在类的字节码文件对象。类名.class
非静态的同步方法，使用的锁是创建的该类对象
public synchronized void show()
{
	
}

9.等待——唤醒机制
调用obj.wait()会立即释放锁，当前线程暂停，释放锁，以便其他线程可以执行obj.notify()
但是notify()不会立刻立刻释放sycronized（obj）中的obj锁，必须要等notify()所在线程执
行完synchronized（obj）块中的所有代码才会释放这把锁。而 yield(),sleep()不会释放锁。

try
{
	r.wait();
}
catch(InterruptedException e)
{
	
}


r.notify();  //唤醒线程，唤醒的是第一个在线程池中等待的线程
             //如果要唤醒多个线程notifyAll()


10.JDK1.5新特性

private Lock lock = new ReentrantLock();   //相当于synchronized
private Condition condition_pro = lock.newCondition();   //相当于锁里的那个Object
condition_pro.await();
condition_con.signal();  //唤醒一个等待线程。

//放在finally里
lock.unlock();  //释放锁的目的就是下一个线程还可以进来


11.中断线程
(1)
Thread t1 = new Thread(new StopThread());
当满足...条件
t1.interrupt();

(2)
自定义终止
class StopThread implements Runnable
{
	private boolean flag = true;
	public void run()
	{
		while(flag)
		{
			System.out.println(Thread.currentThread().getName() + "...run");
			
			//Thread.yield();  //线程释放执行权
		}
	}
	
	public void changeFlag()
	{
		flag = false;
	}
}



12.守护线程
t.setDaemon(true);  //把一个线程改为守护线程
                    //不用刻意去中断线程，只要前台线程一结束，守护线程就会结束

13.join方法   throws InterruptedException
t.join();  //主线程把执行权交给t，此时主线程处于冻结状态，只有等t完全结束，才会执行主线程

例如：
//t1和t2共同抢夺Cpu执行权，只有t1完全结束，主线程才会执行
Thread t1 = new Thread(d);
Thread t2 = new Thread(d);

t1.start();
t2.start();
t1.join();
——————————————————————————————————————————————————————————————————————————————————
1.什么是进程
  一个进程对应一个应用程序——在windows操作系统启动word就表示启动了一个进程，在java的开发环境下启动JVM，就表示启动了一个进程，现在的计算机都是支持多进程的
  ，在同一个操作系统中可以同时启动多个进程

2.多进程有什么作用？
  单进程计算机只能做一件事情，
  玩电脑一边玩游戏（游戏进程） 一边听音乐（音乐进程）
  对于单核计算机来讲，在同一个时间点上音乐进程和游戏进程是同时在运行吗？
  不是，因为计算机的CPU只能在某个时间点上做一件事，由于计算机在游戏进程和音乐进程之间频繁切换执行，切换速度极高，人类感觉游戏和音乐在同时执行

  多进程的作用不是为了提高执行速度，而是提高CPU的使用率
  
  进程和进程之间的内存是独立的

3.什么是线程？
  线程是一个执行中的执行场景，一个进程可以启动多个线程

4.多线程有什么作用？
  多线程不是为了提高执行速度，而是提高应用程序的使用率
  
  线程和线程共享堆内存和方法区内存，占内存是独立的，一个线程一个栈
  可以给现实生活中的人类，多个线程在同时并发进行
  
5.关于Java程序的运行原理
  java命令会启动java虚拟机，启动JVM，等于启动了一个应用程序，表示启动了一个进程，该进程会自动启动一个主线程，主线程区调用某个类的main方法，所以main
  方法运行在主线程中，在此之前所有的程序都是单线程的
  
  扩展：其实更细节说明jvm，jvm启动不止一个线程，还有负责垃圾回收机制的线程
——————————————————————————————————————————————————————
//分析以下程序有几个线程
//以下程序只有一个线程，就是主线程
//main,m1,m2,m3这四个方法在同一个栈中，没有启动其他任何线程

public class ThreadTest
{
	public static void main(String[] args)
	{
		m1();
	}
	
	public static void m1()
	{
		m2();
	}
	
	public static void m2()
	{
		m3();
	}
	
	public static void m3()
	{
		System.our.println("m3....");
	}
}  

——————————————————————————————————————————————————————
/*
	在Java原严重实现多线程的第一种方式
		继承java.lang.Thread;
		重写run方法
	
	三个线程：
		如何定义线程？
		如何创建线程？
			1.定义继承Thread
			2.复写Thread类中的run方法
			3.调用线程的start方法：作用  启动线程    调用run方法
			
		如何启动线程？
*/

//就是main方法一个栈  如果有线程  线程t.start又调用了一个栈
public class ThreadTest
{
	public static void main(String[] args)
	{
		//创建线程
		Thread t = new Prosessor();
		
		//启动
		t.start();   //这段代码执行瞬间结束，告诉java虚拟机再分配一个新的栈给t线程
					 //run方法不需要程序员手动调用，系统启动之后自动调用run方法
					 //意思就是t.start()这段代码和下面的for循环交替运行
		
		//t.run();    //这只是普通方法调用，这样做程序只有一个线程，run方法结束之后，下面的程序才能继续执行
		
		
		//这段代码在主线程中运行
		for(int i = 0 ; i < 10 ;i++)
		{
			System.out.println("i");
		}
		
		//有了多线程之后，main方法结束只是主线程栈中没有方法栈帧了
		//但是其他线程或者其他栈中还有栈帧
		//main方法结束，程序可能还在运行
	}
}

  
 //定义一个线程
class Processor extends Thread
{
	//重写run方法
	public void run()
	{
		for(int i = 0; i < 100; i++)
		{
			System.out.println("run--> + 1");
		}
	}
} 
  
——————————————————————————————————————————————————————————————————————————————————
/*
	java中实现线程的第二种方式
		1.定义类实现Runnable接口
		2.覆盖Runnable接口中的run方法
		   将线程要运行的代码存放在该run方法中
		  
		3.通过Thread建立线程对象
		4.将Runnable接口的子类对象作为实际参数传递给Thread类的构造方法
		  为什么要将Runnerble接口的子类对象传递给Thread的构造函数
		  因为，自定义的run方法所属的对象是Runnerable的子类对象
		  所以要让线程去指定对象的run方法，就必须明确该run方法所属对象
		  
		5.调用Thread类的start方法开启线程并调用Runnerable接口子类的run方法
		
实现方式和继承方式有什么关系？
如果是继承，只能单继承，要是想继承一个类之后又继承Thread，是不可以的，只能通过Runnerable，不免了单继承的局限性

继承Thread：线程代码存放Thread子类run方法中
实现runnerable:现成代码存在接口子类的run方法

*/
  
  
public class ThreadTest
{
	public static void main(String[] args)
	{
		//创建线程
		Thread t = new Thread(new Processor());
		
		//启动
		t.start();
	}
}  
  
//这种方式是推荐的，因为一个类实现接口之外还保留了类的继承
class Processor implements Runnable
{
	public void run()
	{
		for(int i = 10; i < 10; i++)
		{
			System.out.println("run-->");
		}
	}
} 
  
————————————————————————————————————————————————————————————————————

  
																	阻塞状态
												阻塞解除					              阻塞事件
																	
	新建——————————————————————>就绪状态<————————————————————————————————————————————————————————————————————————>运行状态——————————————————>消亡
	  |          start            |                               JVM虚拟机的调度                                  |                        |
      |            |              |                                                                                |                        |
	new表示    线程创建      就绪状态的线程表示有权利去获取CPU的时间片                                         run方法执行           run方法执行结束
	新建状态   之后调用      CPU时间片是执行权，当线程拿到CPU时间片之
			   start方法     后就马上执行run方法，这个时候就代表进入了
			   进入就绪      运行状态
			   状态
  
    就是抢CPU运行时间片，谁抢到了进入运行状态，接着又返回就绪状态又抢
	
	                  临时状态(阻塞)：具备运行资格，但没有执行权
	                     |
    被创建   start()   运行    sleep(time)（当sleep时间到，饭回运行）   冻结：放弃了执行资格，得先回到阻塞状态，有了资格，是否回到运行状态，还要看CPU
	                     |     wait()   只有使用notify()  才可以返回
					 stop()  run方法结束，消亡  
———————————————————————————————————————————————————————————————————————
//线程都有自己默认的名称
//Thread-编号    该编号从0开始
class Test extends Thread
{
	Test(String name)
	{
		super(name);  //调用父类Thread中的构造方法，因为在父类的构造方法当中有传递String的构造方法，就是可以把getName改成name，而不是默认的
	}
	
	public void run()
	{
		for(int x = 0; x < 60; x++)
		{
			System.out.println(this.getName() + "run..." + x);
			//Thread.currentThread().getName()   currentThread是静态方法，返回对当前正在执行的线程对象的引用。
			//和this一样
		}
	}
}

class ThreadTest
{
	public static void main(String[] args)
	{
		
	}
}




————————————————————————————————————————————————————————————————————————
2.4线程的调度与控制
分时调度模型：所有线程轮流使用CPU的使用权，平均分配每个线程占用CPU的时间片
抢占式调度模型：优先让优先级高的线程使用CPU，如果线程的优先级相同，那么会随机选择一个，优先级高的线程获取的CPU时间片相对多一些

2.4.1线程优先级
MAX_PRIORITY(最高级10);MIN_PRIORITY(最低级1),NORM_PRIORITY(标准5)默认  
/*
	三个方法
		1.获取当前线程对象 Thread.currentThread();
		2.给线程起名  t.setName("t1");
		3.获取线程的名字  t.getName();
*/
  
public class ThreadTest04
{
	public static void main(String[] args)
	{
		//如何获取当前线程对象
		Thread t = Thread.currentThread();   //t保存的地址指向的线程只“主线程对象”
		
		System.out.println(t.getName());  //获取该线程的名字
		
		Processor p = new Processer();
		Thread t1 = new Thread(p);
		
		//给线程起名
		t1.setName("t1");
		t1.start();
		
	}
} 
  
class Processor implement Runnable
{
	public void run()
	{
		Thread t = Thread.currentThread();   //t保存的内存地址指向的线程是“t1线程对象”
		System.out.println(t.getName());   //Thread-0   再调用一次，输出Thread-1
	}
}
  
_____________________________________________________________________________________________________________________________________________________

/*
	线程优先级高的获取的CPU时间片相对多一些
	优先级：1-10
	最低 1    MIN_PRIORITY
	最高 10   MAX_PRIORITY
	默认 5    NORM_PRIORITY
	
*/
  
public class ThreadTest04
{
	public static void main(String[] args)
	{
		//刚开始优先级都是5
		Thread t1 = new Processor();  
		t1.setName("t1");
		
		Thread t2 = new Processor();
		t2.setName("t2");
		
		//设置优先级
		t1.setPriority(1);
		t2.setPriority(10);
		
		//启动线程
		t1.start();
		t2.start();
	}
}
  
  
class Processor implement Runnable
{
	public void run()
	{
		for(int i = 0; i < 50; i++)
		{
			System.out.println(Thread.currentThread().getName() + "---->" + i);
		}
	}
}	
  
  
——————————————————————————————————————————————————————————————————————————————————————————
  
public class ThreadTest06
{
	public static void main(String[] args) throws InterruptedException
	{
		Thread t1 = new Processor();
		t1.setName("t1");
		t1.start();
		
		for(int i = 0; i < 10; i++)
		{
			System.out.println(Thread.currentThread().getName() + "---->" + i);
			Thread.sleep(500);   //让当前阻塞0.5s
		}
	}	
}
  
  
class Processor extends Thread
{
	//Thread 中的run方法不跑出异常，所以重写run方法之后，在run方法的声明位置上不能使用throws
	//所以run方法中方的异常只能使用try..catch..
	public void run()
	{
		for(int i = 0; i < 10; i++)
		{
			System.out.println(Thread.currentThread().getName() + "---->" + i);
			try
			{
				Thread.sleep(1000);   //让当前阻塞1s
			}
			catch( InterruptedException)
			{
				e.printStackTrace();
			}
		}
		
		//m1();
	}
	
	/*
		m1方法时可以使用throws
		public void m1() throws Exception
		{
			
		}
	
	*/
}
  
______________________________________________________________________________________
  
/*
	面试题
*/
  
public class ThreadTest
{
	public static void main(String[] args) throws Exception
	{
		Thread t = new Processor();
		t.setName("t");
		
		t.start();
		
		//下面两个是等价的，sleep写在哪个里面，阻塞的就是哪个线程，和t无关
		Thread.sleep(5000);
		//也可以写成
		t.sleep(5000);
	}
}
  
  
class Processor extends Thread
{
	public void run()
	{
		for(int i = 0; i < 3000; i++)
		{
			System.out.println(Thread.currentThread().getName() + "----->" + i);
		}
	}
}

————————————————————————————————————————————————————————————————————————————————————————

//某线程正在休眠，如何打断他的休眠
public class ThreadTest
{
	public static void main(String[] args) throws Exception
	{
		//需求：启动线程，5s之后打断线程的休眠
		Thread t = new Thread(new Processor());
		t.setName("t");
		
		t.start();
		
		//5s之后
		Thread.sleep(5000);
		
		//打断t的休眠
		t.interrupt();
		
	}
}
  
  
class Processor implement Runnable
{
	public void run()
	{ 
		try
		{
			Thread.sleep(100000000);
		}
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}
		
		for(int i = 0; i < 10; i++)
		{
			System.out.println(Thread.currentThread().getName() + "----->" + i);
		}
		
	}
}
  
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
/*
	如何正确的更好的终止一个正在执行的线程
	
	需求：线程启动5s后终止
*/
  

public class ThreadTest
{
	public static void main(String[] args) throws Exception
	{
		Processor p = new Processor();
		
		Thread t = new Thread(p);
		t.setName("t");
		
		t.start();
		
		//5s之后
		Thread.sleep(5000);
		
		//终止
		p.run = false;
	}
}	
  
  
class Processor implement Runnable
{
	boolean run = true;
	
	public void run()
	{ 
		if(run)
		{
			try
			{
				Thread.sleep(100000000);
			}
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			
			for(int i = 0; i < 10; i++)
			{
				System.out.println(Thread.currentThread().getName() + "----->" + i);
			}
		}
		else
			return;
	}
}	
  
===============================================================================================================================================================
Thread.yield();
1.该方法是一个静态方法
2.作用：给同一个优先级的线程让位。阻塞当前线程，但是让位时间不固定
3.和sleep方法相同，就是yield时间不固定

public class ThreadTest
{
	public static void main(String[] args) throws Exception
	{
		Thread t = new Processor();  //如果是这种形式，就是Thread是爸爸，processor是儿子，
		t.setName("t");
		
		t.start();
		
		for(int i = 0; i < 500; i++)
		{
			System.out.println(Thread.currentThread().getName() + "----->" + i);
		}
	}
}	
  
  
class Processor extends Thread
{
    public void run()
	{ 
		for(int i = 0; i < 1000; i++)
		{
			
			System.out.println(Thread.currentThread().getName() + "----->" + i);
			
			if(i % 20 == 0)
			{
				Thread.yield();
			}
		}
	}
}	

===============================================================================================================================================================
t.join (成员方法)
/*
	关于线程的合并
*/
  
public class ThreadTest
{
	public static void main(String[] args) throws Exception
	{
		Thread t = new Thread(new Processor());
		t.setName("t");
		
		t.start();
		
		//合并线程  这个线程出现在啥中，就会和哪个线程合并，变成了单线程
		t.join();
		
		for(int i = 0; i < 10; i++)
		{
			System.out.println(Thread.currentThread().getName() + "----->" + i);
		}
	}
}	
  
  
class Processor implements Runnable
{
    public void run()
	{ 
			
		for(int i = 0; i < 5; i++)
		{
			try
			{
				Thread.sleep(1000);
			}
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
			
			System.out.println(Thread.currentThread().getName() + "----->" + i);
		}
	}
}	 
  
================================================================================================================================================================
线程的同步
/*
	t1和t2
	异步编程模型：t1执行t1的，t2执行t2的，谁也不等谁
	同步执行模型：当t1线程必须等t2线程执行之后，t1线程才可以执行
	
	什么时候要同步呢？为什么要引入线程同步呢？
	为了数据的安全，暂时不考虑效率。线程同步机制使程序等同单线程
	
	什么条件下要使用线程同步
	必须是多线程环境，多线程环境共享一个数据，共享的数据涉及到修改操作
*/
  
  
//以下程序演示取款例子
public class Thread
{
	public class void main(String[] args)
	{
		//创建一个公共的账户
		Account act = new Account("actno-001",5000.0);
		
		//创建线程对同一个账户取款
		Porcessor p = new Processor(act);
		
		Thread t1 = new Thread(p);
		Thread t2 = new Thread(p);
		
		t1.start();
		
		t2.start();
	}
} 

//取款线程
class Porcessor implement Runnable
{
	//账户 
	Account act;
	
	Porcessor(Account act)
	{
		this.act = act;
	}
	
	public void run()
	{
		act.withdraw(1000.0);
		System.out.println("取款成功，余额：" + act.getBalance());
	}
}


  
 //账户
 class Account
 {
	private String actor;
	private double balance;
	
	public Account() {}
	public Account(String actor, double balance)
	{
		this.actor = actor;
		this.balance = balance;
	}
	
	public void setActor(String actor)
	{
		this.actor = actor;
	}
	
	public String getActor()
	{
		return actor;
	}
	
	public void setBalance(double balance)
	{
		this.balance = balance;
	}
	
	public String getBalance()
	{
		return balance;
	}
	
	//对外提供一个取款的方法
	//public synchronized void withdraw(double money)
	//意思就是这个打括号里的所有代码全部需要线程同步
	//synchronized关键字添加到成员方法上，线程拿走的也是this对象锁
	public void withdraw(double money)
	{
		//把需要同步的代码放到同步语句块中
		/*
			原理：t1线程和t2线程
			t1如果执行到此处，遇到了synchronized关键字，就会去找this的对象锁，如果找到this对象锁，则进入了同步语句块中执行程序。当同步语句块中的代码
			执行结束之后，t1线程归还this的对象锁
			
			在t1线程执行同步语句块的过程中，如果t2线程也过来执行以下代码，也遇到synchronized关键字，所以也去找this的对象锁，但是该对象锁被t1线程持有
			只能在这等待this对象的归还
		*/
		synchronized(this)
		{
			double before = this.balance;
			double after = before - money;
			
			//可以在这里加一个延迟
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e)
			{
				
			}
			this.setBalance(after);
		}
	}
 }
 
____________________________________________________________________________________________________________________________________

/*
通过分析，发现，打印出0，-1，-2等错票

多线程运行出现了安全问题

问题的原因：
	当多条语句在操作同一个线程共享数据时，一个线程对多条语句只执行了一部分，还没执行完
	另一个线程参与进来执行，导致共享数据的错误

解决办法：
	对多条操作共享数据的语句，只能让一个线程都执行完，在执行过程中，其他线程不可以参与执行
	
Java对于多线程的安全问题提供了专业的解决方案
就是同步代码块

synchronized(对象)
{
	需要被同步的代码
}

同步的前提：
1.必须要有两个或两个以上的线程
2.必须是多个线程使用同一个锁

必须保证同步中只能有一个线程在运行

好处：解决了多线程的安全问题
弊端：多个线程需要重复判断锁，较为消耗资源

如何找哪些应该同步：
1.明确哪些是多线程运行代码
2.明确共享数据
3.明确多线程运行代码中哪些是操作共享数据的，就把操作共享数据的用synchronized括起来
——————————————————————————————————————————————————————————————————————————————————

同步函数

也可以在函数上直接加synchronized，同步函数使用的锁是this
因为函数需要被对象调用。那么函数都有一个所属对象引用。就是this
同步代码块的锁是object()，也可以是this 如果同步代码块和同步函数的锁不是一个就不安全
/*
	如果同步函数被静态修饰后，使用的锁是什么呢？
	通过验证，发现不再是this，因为静态方法中也不可以定义this
	静态进内存时，内存中没有本类对象，但是一定有该类对应的字节码文件对象
	类名.class  该对象的类型是class
	
	所以写的时候写synchronized(Ticket.class)
*/

class Ticket implements Runnable
{
	private int tick = 1000;
	public void run()
	{
		while(true)
		{
			this.show();
		}
	}
	
	public synchronized void show()
	{
		if(tick > 0)
		{
			try{Thread.sleep(10);}catch(Exception e){}
			tick--;
		}
	}
}


class Ticket implements Runnable
{
	private int tick = 100;
	public void run()
	{
		while(true)
		{
			if(tick > 0)
			{
				try
				{
					Thread.sleep(10);   //让一个线程执行到这里的时候停一会儿，下一个线程继续，所以说如果是1的话，就有可能由于这个线程执行一会儿，另一个
					                    //再执行发生错误
				}
				catch(Exception e)
				{}
		
				System.out.println(Thread.currentThread().getName() + "...sale ：" + tick--);
			}
		}
	}
}

--------------------------------------

class Ticket implements Runnable
{
	private int tick = 100;
	Object obj = new Object();  //这个object对象就是一个锁，啥对象都行，只要是对象，就是锁
	
	public void run()
	{
		while(true)
		{
			synchronized(obj)   //如果说加上这个当一个线程执行的时候，就会将1改成0，只有这个线程执行完后，才会将1改成0，其他才可以进来
			{
				if(tick > 0)
				{
					try
					{
						Thread.sleep(10);   //让一个线程执行到这里的时候停一会儿，下一个线程继续
					}
					catch(Exception e)
					{}
					
					System.out.println(Thread.currentThread().getName() + "...sale ：" + tick--);
				}
			}
		}
	}
}
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

多线程——单例设计模式

//懒汉式单例
/*
	懒汉式的目的在于延迟加载，如果多线程访问时，会出现安全问题，可以加同步来解决，而加同步的方式，用同步代码块和同步函数都可以
	但是稍微有些低效，用双重判断的形式解决这个效率问题，加同步的时候，使用的锁是哪一个，该类所属的字节码文字对象
	
	啥时候会出现安全问题，就是仅仅只有一个用的，很多线程来访问就会出现安全问题	
*/

class Single
{
	private static Single s = null;
	private Single(){}
	
	public static Single getInstance()
	{
		/*
			有两个限制条件：跟锁判断的效率不如和null判断的效率，第二，创建对象只执行一次
			
		*/
		if(s == null)
		{
			synchronized(Single.class)   //如果加在函数上面，每个进来的线程都会跟锁判断一下，效率不高，先判断是否为空
			{
				if(s == null)
					s = new Single();
			}
		}
		
		return s;
	}
}


//饿汉式单例模式
class Single
{
	private static final Single s = new Single();  //这里已经创建好对象，不会出现线程不同结果不同的结果
	private Single(){}
	
	public static Single getInstance()
	{
		return s;
	}
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//面试题

/*
	通过验证发现 同步函数如果被静态修饰后，不再以this 为锁

	静态进内存时，内存中没有本类对象，但是一定有该类的字节码文件对象
	类名.class  该对象的类型是class


	静态的同步方法，使用的锁是该方法所在类的字节码文件对象。类名.class
	非静态的同步方法，使用的锁是创建的该类对象
*/

/*
	创造了t1和t2两个线程，这两个线程抢cpu执行权，有可能在m1执行的半中间，t2抢到了，又开始执行t2
	就是抢一点，执行一点，，如果函数头同步，两个函数的锁对象是相同的，一个线程只能等待另一个线程执行完

*/

public class threadTest
{
	public static void main(String[] args) throws Exception
	{
		MyClass mc = new MyClass();
		Processor p = new Processor(mc);
		
		Thread t1 = new Thread(p);
		t1.setName("t1");
		Thread t2 = new Thread(p);
		t2.setName("t2");
		
		//启动线程
		t1.start();
		
		//保证t1线程先启动，并执行run
		//加一个延迟
		Thread.sleep(1000);
		
		t2.start();
		
		
	}
}

class Processor implements Runnable
{
	MyClass mc;
		
	Processor(MyClass mc)
	{
		this.mc = mc;
	}
	
	public void run()
	{
		if(Thread.currentThread().getName().equals("t1"))
		{
			mc.m1();
		}
		
		else if(Thread.currentThread().getName().equals("t2"))
		{
			mc.m2();
		}	
	}
}

//下面这两个同步函数所用的锁对象都是上面创建的MyClass对象mc，所以说m1和m2所用的锁对象是相同的
//如果加同步，这两个只可以执行一个
class MyClass
{
	public synchronized void m1()
	{
		try
		{
			Thread.sleep(100000);
		}
		catch(Exception e)
		{}
		
		System.out.println("t1");
	}
	
	/*
	m2方法的执行不需要等m1方法的结束，因为m2方法上没有synchronized，看有没有synchronized基于二者共享一个对象
	public void m2()
	{
		System.out.println("t2");
	}
	*/
	
	//
	public synchronized void m2()
	{
		System.out.println("t2");
	}
}
  
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
  
/*
	类锁：类只有一个，所以锁是类级别的，只有一个
*/
  
public class Thread
{
	public static void main(String[] args) throws Exception
	{
		MyClass mc1 = new MyClass();
		MyClass mc2 = new MyClass();  
		
		Thread t1 = new Thread(new Processer(mc1));
		Thread t2 = new Thread(new Processer(mc2));
		
		t1.setName("t1");
		t2.setName("t2");
		
		t1.start();
		
		//延迟，保证t1先执行
		Thread.sleep(1000);
		
		t2.start();
	}
} 

//不会等m1结束，因为该方法没有被synchronized修饰
class Processer implements Runnable
{
	MyClass mc;
		
	Processor(MyClass mc)
	{
		this.mc = mc;
	}
	
	
	public void run()
	{
		if(Thread.currentThread().getName().equals("t1"))
		{
			mc.m1();
		}
		
		else if(Thread.currentThread().getName().equals("t2"))
		{
			mc.m2();
		}	
	}
}
  
class MyClass
{
	synchronized添加到静态方法上，线程执行此方法的时候会找类锁
	public synchronized static void m1()
	{
		try
		{
			Thread.sleep(100000);
		}
		catch(Exception e)
		{}
		
		System.out.println("m1");
		
		public void m2()
		{
			System.out.println("t2");
		}
	}
}  
  
——————————————————————————————————————————————————————————————————————————————————————————————————————————
//死锁

public class DeadLock
{
	public static void main(String[] args)
	{
		Object o1 = new Object();
		Object o2 = new Object();
		
		Thread t1 = new Thread(new T1(o1,o2));
		Thread t2 = new Thread(new T2(o1,o2));
		
		t1.start();
		t2.start();
	}
	

}
  
  
class T1 implements Runnable
{
	Object o1;
	Object o2;
	
	T1(Object o1, Object o2)
	{
		this.o1 = o1;
		this.o2 = o2;
	}
	
	public void run()
	{
		synchronized(o1)   //o1就相当于钥匙，只有这个括号结束，钥匙才会给别人
		{
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e){}
			
			synchronized(o2)  //o2的钥匙已经给了别人两人互相僵持，谁的要是也不愿意给出
			{
				
			}
		}
	}
  
class T2 implements Runnable
{
	Object o1;
	Object o2;
	
	T2(Object o1, Object o2)
	{
		this.o1 = o1;
		this.o2 = o2;
	}
	
	public void run()
	{
		synchronized(o2)
		{
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e){}
			
			synchronized(o1)
			{
				
			}
		}
	}
}   
  
————————————————————————————————————————————————————————————————————————————————————————————————————————————

线程间通信——解决安全问题

class Res
{
	String name;
	String sex;
	boolean flag = false;
}

class Input implements Runnable
{
	private Res r;
	Input(Res r)
	{
		this.r = r;
	}
	
	public void run()
	{
		int x = 0;
		while(true)
		{
			/*
				wait;
				notify();
				notifyAll();
				
				都使用在同步中，因为要对持有监视器（锁）的线程操作
				所以要使用在同步中，因为只有同步才具有锁
				
				为什么这些操作线程的方法要定义在object中
				因为这些方法在操作同步中线程时，都必须要标识他们所操作的线程持有的锁
				只有同一个锁上的被等待线程可以被同一个锁上的notify唤醒，不可以对不同锁上的线程进行唤醒
				
				也就是等待和唤醒必须是同一把锁，而锁可以使任意对象，所以可以被任意对象调用的方法定义在object中
				
				  
			*/
			synchronized(r)
			{
				if(r.flag)
					try{r.wait();}catch(Exception e){}   //等待线程，让这个线程等待,r.wait()持有wait这个锁的线程
					
				if(x == 0)
				{
					r.name = "mick";
					r.sex = "man";
				}
				else
				{
					r.name = "丽丽";
					r.sex = "哪哪哪哪哪哪哪";
				}
				
				x = (x + 1) % 2;
				r.flag = true; 
				
				r.notify();   //notify(); 唤醒线程，唤醒的是第一个在线程池中等待的线程，如果是只有一个notify(); 的话
				            //如果要唤醒多个线程notifyAll() 
			}
		}
	}
}

class Output implements Runnable
{
	private Res r;
	
	Output(Res r)
	{
		this.r = r;
	}
	
	public void run()
	{
		while(true)
		{
			synchronized(r)  //如果这个和上面加你实现同一个锁，就是这两个只可以执行一个，一个执行完才可以执行另一个
			{
				if(!r.flag)
					try{wait();}catch(Exception e){}
				System.out.println(r.name + "...." + r.sex);
				r.flag = false;
				notify();
			}
		}
	}
}

class InputOutDemo
{
	public static void main(String[] args)
	{
		Res r = new Res();
		
		Input in = new Input(r);
		Output out = new Output(r);
		
		Thread t1 = new Thread(in);
		Thread t2 = new Thread(out);
		
		t1.start();
		t2.start();
	}
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————
//下面这个是正确的
class Res
{
	private String name;
	private String sex;
	private boolean flag = false;
	
	//设置flag的目的就是先建立，这个建立的一定要输出
	//建立一次，输出一次
	public synchronized void set(String name, String sex)
	{
		if(flag)
			try{this.wait();}catch(Exception e){}
		this.name = name;
		
		this.sex = sex;
		flag = true;
		this.notify();
	}
	
	public synchronized void out()
	{
		if(!flag)
			try{this.wait();}catch(Exception e){}
		
		System.out.println(name + "......." + sex);
		
		flag = false;
		this.notify();
	}
}



class Input implements Runnable
{
	private Res r;
	
	Input(Res r)
	{
		this.r = r;
	}
	
	public void run()
	{
		int x = 0;
		while(true)
		{
			if(x == 0)
				r.set("mike", "man");
			else
				r.set("丽丽"，"哪哪哪哪哪哪哪");
			x = (x + 1) % 2;
		}
	}
}


class Output implements Runnable
{
	private Res r;
	
	Output(Res r)
	{
		this.r = r;
	}
	
	public void run()
	{
		while(true)
		{
			r.out();
		}
	}
}


class InputOutDemo2
{
	public static void main(String[] args)
	{
		Res r = new Res();
		
		new Thread(new Input(r)).start();
		new Thread(new Output(r)).start();
	}
}

======================================================================================

当出现多个读取线程和多个写入线程的时候

class Resource
{
	
	private String name;
	private int count = 1;
	private boolean flag = false;
	
	/*
		我来简述一下这个过程
		首先假设执行1线程，flag = true，停止1线程
		假设第二个执行的是2线程，停止了2线程
		第三个执行的是3线程，flag = false，1和2线程恢复，3线程停止
		
		这样就保证了生产一次，卖出一次
	
	*/
	//t1 t2
	
	public synchronized void set(String name)
	{
		while(flag)  //如果不用while循环，用if如果刚好卡到wait，下一次就会直接往下执行，因为释放的是所有的
			try{this.wait();}catch(Exception e){}
			
		this.name = name + "--" + count++;
		
		System.out.println(Thread.currentThread().getName() + "..生产者.." + this.name);
		
		flag = true;
		this.notifyAll();   //恢复所有的线程
	}
	
	public synchronized void out()
	{
		while(!flag)
			try{this.wait();}catch(Exception e){}
		System.out.println(Thread.currentThread().getName() + "..消费者.." + this.name);
		flag = false;
		this.notifyAll();
	}
}

==============================================================================================
/*
	JDK1.5中提供了多线程升级解决方案
	将同步Synchronized替换成现实的Lock操作
	将Object中的wait，notify，notifyAll，替换成了Condition对象
	该对象可以Lock锁，进行获取
	该示例中，实现了只唤醒对方的操作
*/

class Resource
{
	private String name;
	private int count = 1;
	private boolean flag = false;
	
	private Lock lock = new ReentrantLock();   //相当于synchronized
	
	//一个锁上可以有多个对象
	private Condition condition_pro = lock.newCondition();   //相当于锁里的那个Object
	private Condition condition_con = lock.newCondition(); 
	
	//t1 t2
	public void set(String name) throws InterruptedException
	{
		lock.lock();
		
		try		
		{
			while(flag)
				condition_pro.await();
			this.name = name + "--" + count++;
			
			System.out.println(Thread.currentThread().getName() + "..生产者.." + this.name);
			flag = true;
			condition_con.signal();  //唤醒一个等待线程。
		}
		finally
		{
			lock.unlock();  //释放锁的目的就是下一个线程还可以进来
		}
	}
	
	//t3 t4
	public synchronized void out()
	{
		lock.lock();
		
		try
		{
			while(!flag)
				condition_con.await();
				
			System.out.println(Thread.currentThread().getName() + "..消费者.." + this.name);
			flag = false;
			condition_pro.signalAll();
		}
		finally
		{
			lock.unlock();
		}
	}
}
====================================================================================================================================
停止线程
/*
stop方法已经过时

如何停止线程？
只有一种，run方法结束
开始多线程运行，运行代码通常是循环结构

只要控制住循环，就可以让线程结束

特殊情况：
当线程处于了冻结状态
就不会读取到标记，那么线程就不会结束

当没有指定的方式让冻结的线程恢复到运行状态时，这是需要对冻结进行清楚，
强制让线程恢复到运行状态中来，这样就可以操作标记让线程结束

Thread类中提供了该方法 interrupt();方法

class StopThread implements Runnable
{
	private boolean flag = true;
	public synchronized void run()
	{
		while(flag)
		{
			try
			{
				wait();  //两个线程来到这里都失去了资格
			}
			catch(InterruptedException e)
			{
				System.out.println(Thread.currentThread().getName() + "...Exception");
				flag = false;
			}
			System.out.println(Thread.currentThread().getName() + "...run");
		}
	}
	
	public void changeFlag()
	{
		flag = false;
	}
}


class StopThreadDemo
{
	public static void main(String[] args)
	{
		StopThread st = new StopThread();
		
		Thread t1 = new Thread(st);
		Thread t2 = new Thread(st);
		
		t1.start();
		t2.start();
		
		int num = 0;
		
		while(true)
		{
			if(num++ == 60)
			{
				t1.interrupt();
				t2.interrupt();
				break;
			}
			System.out.println("main....");
		}
	}
}

*/

class StopThread implements Runnable
{
	private boolean flag = true;
	public void run()
	{
		while(flag)
		{
			System.out.println(Thread.currentThread().getName() + "...run");
			
			//Thread.yield();  //线程释放执行权
		}
	}
	
	public void changeFlag()
	{
		flag = false;
	}
}

class StopThreadDemo
{
	public static void main(String[] args)
	{
		StopThread st = new StopThread();
		
		Thread t1 = new Thread(st);
		Thread t2 = new Thread(st);
		
		t1.start();
		t2.start();
		
		int num = 0;
		
		while(true)
		{
			if(num++ == 60)
			{
				//st.changFlag();
				st.changeFlag();
				break;
			}
			System.out.println("main....");
		}
	}
}

======================================================================================================

守护线程 
setDaemon  该方法必须在启动线程前调用,就是他时后台线程，一般来说，你所看到的线程都是前台线程
		   如果把线程标记成后台线程，特点是开启后和前台线程共同抢夺cpu的执行权运行，当所有的前台线程都结束后，后台线程会自动结束
t1.setdaemon(true);
t1.start();

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
join当A线程执行到了B线程的join方法时，A线程就会等待，等B线程都指向完，A才会执行，Join可以用来临时加入线程执行
class Demo implements Runnable
{
	public void run()
	{
		for(int x = 0; x < 70; x++)
		{
			System.out.println(Thread.currentThread().getName() + "....." + x);
		}
	}
}

class JoinDemo
{
	public static void main(String[] args) throws Exception
	{
		Demo d = new Demo();
		Thread t1 = new Thread(d);
		Thread t2 = new Thread(d);
		
		t1.start();
		
		t1.join();   //主线程等待t1完全结束，它才活过来，才能执行
		
		t2.start();
		
		for(int x = 0; x < 80; x++)
		{
			System.out.println("main...." + x);
		}
		
		System.out.println("over");
	}
}
——————————————————————————————————————————————————————————————————————————————
做项目时如何写
class ThreadTest{
	public static void main(String[] args)
	{
		new Thread()
		{
			public void run()
			{
				for(int x = 0; x < 100; i++)
				{
					System.out.println(Thread.currentThread().getName + "..." + x);
				}
			}
		}.start();
		
		for(int x = 0; x < 100; i++)
		{
			System.out.println(Thread.currentThread().getName + "..." + x);
		}
		
		Runnable r = new Runnable()
		{
			public void run()
			{
				for(int x = 0; x < 100; i++)
				{
					System.out.println(Thread.currentThread().getName + "..." + x);
				}
			}
		};
		
		new Thread(r).start();
	}
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
线程分类：
1.用户线程：以上讲的都是用户线程
2.守护线程：所有的用户线程结束生命周期，守护线程才会结束生命周期，只要有一个用户线程存在，守护线程就不会结束，垃圾回收器就是一个守护线程，守护线程一般都是无限执行的

//守护线程
public class Thread
{
	public static void main(String[] args)
	{
		Thread t1 = new Processor();
		
		t1.setName("t1");
		
		//将t1这个用户线程修改成守护线程
		t1.setDaemon(true);
		
		t1.start();
		
		for(int i = 0; i < 10; i++)
		{
			System.out.println(Thread.currentThread().getName() + "--->" + i)
			Thread.sleep(1000);
		}
	}
}
  
class Processsor extends Thread
{
	public void run()
	{
		int i = 0;
		while(true)
		{
			i++;
			System.out.println(Thread().getName() + "-->" + i);
			
			try
			{
				Thread.sleep(500);
			}
			catch(Exception e) {}
		}
	}
}  
  
===================================================================================================================================================================
/*
	关于定时器的应用：
	作用：每隔一段固定的时间执行一段代码

*/
  
public class Thread
{
	public static void main(String[] args) throws Exception
	{
		//创建定时器
		Timer t = new Timer();
		
		//指定定时任务
		t.schedule(new LogTimeTask(), new SimpleDateFormat("yyyy-MM-dd HH:mm:ss SSS").parse("2012-08-03 17:35:00 000", 10 * 1000));
		
		
	}
}	
  
//指定定时任务
class LogTimeTask extends TimerTask
{
	public void run()
	{
		System.out.println("jikfs");
	}
} 
  
==================================================================================================================================================================
反射
====
以下是SUN提供反射机制中的类
java.lang.Class;                         相当于整个类 User
java.lang.reflect.Constructor;           相当于public User(){}
java.lang.reflect.Field;                 private String name;
java.lang.reflect.Method;                private void m1(){};;
java.lang.reflect.Modifier;              修饰符public之类

class User
{
	private String name;
	public User(){}
	private void m1(){};
}


1.反射机制的作用：
	1.反编译：.class-->.java
	2.通过反射机制访问java对象的属性，方法，构造方法等
	
————————————————————————————————————————————————————————————————
/*
	获取class对象的三种方式
	就是获取class文件的方法
*/、

public class Reflect
{
	public static void main(String[] args) throws Exception
	{
		//第一种方式Employee就是代表类
		Class c1 = Class.forName("Employee");//c1引用保存内存地址指向堆中的对象，该对象代表的是Emploee.class整个文件
		
		//第二种方式 
		//java中每个类型都有.class 属性 
		Class c2 = Employee.class;
		
		//第三种方式
		//Java语言中任何一个Java对象都有getClass方法
		Emploee e = new Employee();
		Class c3 = e.getClass();     //c3是运行时类（e的运行时类时Employee）
		
		Class c4 = Date.class; //代表Data这个类,系统提供的
		Class c5 = Class.forName("java.util.Date");  //必须写类全名，类全名带有包名
		
	    Date d = new Date();
		Class c6 = d.getClass();

		//c7代表 int 类型 
		Class c7 = int.class;
	}
}

//假设把class文件删除，只留一个.java文件
public class Employee
{
	private String name;
	
	public Employee()
	{
		
	}
	
	public Employee(String naem)
	{
		this.name = name;
	}
	
	public void work()
	{
		System.out.println(name + "在工作");
	}
}

——————————————————————————————————————————————————————————————————————————————————

public class Reflect
{
	public static void main(String[] args) throws Exception
	{
		//将A.class文件装载到JVM中的过程
		Class.forName("A");
		
		//不会执行静态语句块
		Class c = A.class;
		
		//这个肯定运行,在new的时候就已经类加载了
		A a = new A();
		Class c = a.getClass();
	}
}

class A 
{
	static 
	{
		System.out.println("A...");
	}
}

———————————————————————————————————————————————————————————————————————————————————
//获取Class类型的对象之后，可以创建该类的对象
public class Reflect
{
	public static void main(String[] args) throws Exception
	{
		Class c = Class.forName("Emploee");
		
		//创建此Class对象所表示的类的一个新实例
		Object o = c.newInstance();  //调用了Employee的无参数构造方法
									 //创建由此类对象表示的类的新实例。 
		
		System.out.println(o);  //Employee@c17164
		
	}
}

——————————————————————————————————————————————————————————————————————————————————

可变长参数
public class Reflect
{
	//m1方法有一个int类型可变长参数
	public static vid m1(int... a)   //m1方法在调用的时候，传递的实参可以使0-N个
	{
		System.out.println("Test");
	}	
	
	//如果可以精确匹配的方法，则调用该方法，不会再去执行可变长参数的那个方法
	public static void m1(int i)
	{
		System.out.println(i);
	}
		
	//变长数组可以等同看作数组
	public static void m2(String... args)
	{
		for(int i = 0; i < args.length; i++)
		{
			System.out.println(args[i]);
		}
	}
	
	public static void m3(Class... args)
	{
		for(int i = 0; i < args.length; i++)
		{
			Class c = args[i];
			System.out.println(c.newInstance());
		}
	}
	
	//可变长参数只能出现一次，并且只能出现在所有参数的最后一位
	public static void m4(int i,String... a){}
	
	public static void main(String[] args) throws Exception
	{
		m1();
		m1(1);
		m1(1,2);
		m1(3,4,5,6,7);
		
		m2("孙燕姿","梅艳芳","王菲");
		
		m3(Date.class, Employee.class);
	}
}


———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


dbinfo这样的文件我们称之为配置文件，配置的文件的作用就是，使程序更加灵活
一般在程序中可变的东西不要写死。推荐写到配置文件中
运行同样的程序得到不同的结果

像dbinfo这样的一个具有特殊内容的配置文件我们又叫做：属性文件。
Java规范中要求属性文件以".properties"结束

有一个文件：username = list(中间的连接符可以使空格，冒号，等号，如果一行中既有空格又有冒号等号之类，就选出现第一个的为分割符)
Public class Test
{
	public static void main(String[] args) throws Exception
	{
		//1.创建属性对象
		Properties p = new Properties();   //和Map一样，只不过key和value只能储存字符串类型
		                                   //key不能重复，如果key重复则value覆盖
										   
		//2.创建输入流
        FileInputStream fis = new FileInputStream("dbinfo");
        
        //3.将fis流中的所有数据加载到属性对象中
		p.load(fis); //所以现在属性对象中有（key = username, value = scott）
		
		//4.关闭流
		fis.close();
		
		//通过key获取value
		String v = p.getProperty("username");
		
		System.out.println(v);
	}
}




———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

反射机制 + IO + Properties的联合应用 + 动态创建java对象
className = java.util.Date

/*
	IO + Properties
	dbinfo这样的文件我们称作配置文件
	配置文件的作用就是，是程序更加灵活
	
	注意：一般在程序中可变的东西不要写死，推荐写到配置文件中去
	运行同样的程序得到不同的结果，key不可以改
	像dbinfo这样一个具有特殊内容的配置文件我们又叫做：属性文件
	java规范中要求属性文件以".properties"结束，不是必须的
	
	name = zhangsan 
	jsi = some
	
	属性文件中数据要求：
		key和value之间可以使用”空格“，”冒号“，”冒号“
		如果”空格“，”冒号“，”冒号“都有，按最前面的当作分隔符
		
	—————————————————————
	如果有中文，转化成unicode码写进去
	
	native2ascii \n
	把要转化的中文写在这里 \n
	
	
*/
Public class Test
{
	public static void main(String[] args) throws Exception
	{
		Properties p = new Properties();   //和Map一样，只不过key和value只能储存字符串类型
		                                   //key不能重复，如果key重复则value覆盖
										   
		//2.创建流
        FileReader fr = new FileReader("classInfo.properties");
        
        //3.将fis流中的所有数据加载到属性对象中
		p.load(fr); //所以现在属性对象中有（key = username, value = scott）
		
		//4.关闭流
		fr.close();
		
		//通过key获取value
		String className = p.getProperty("className");
		
		//System.out.println(className);
		
		Class c = Class.forName("className");
		
		//创建此Class对象所表示的类的一个新实例
		Object o = c.newInstance();  //调用了Employee的无参数构造方法
		
		System.out.println(o); 
	}
}

——————————————————————————————————————————————————————————————————————————————
classIofo.properties
className=java.util.Date

public static Test01{
	public static void main(String[] args) throws Exception
	{
		Propertise p = new Propertise();
		
		FileReader fr = new FileReader("classInfo.properties");
		
		p.load(fr);
		
		fr.close();
		
		String className = p.getProperty("className");
		
		System.out.println(className);
		
		——————————————————————————————————————————————————————
		
		//通过反射机制创建对象
		//返回与给定字符串名称的类或接口相关联的[类对象]。
		//clasName所对应的是啥类型，c就是啥类型，不需要二次编译，使程序更加灵活
		Class c = Class.forName(className);
		
		//创建对象
		Object o = c.newInstance();
		
		System.out.println(o);
	}
}

==================================================================================

/*
	java.lang.reflect.Field;  //类中的属性
*/

public class ReflectTest
{
	public static void main(String[] args) throws Exception{
		
		//获取整个类
		Class c = Class.forName("User");
		
		获取属性Field
		//获取所有public修饰的属性
		/*
		Field[] fs = c.getFields();
		System.out.println(fs.length);
		System.out.println(fs[0].getName());
		*/
		
		//获取所有的属性
		Field[] fs = c.getDeclaredFields();
		for(Field field : fs){
			
			//得到String Boolean类型的方法
			Class type = field.getType();
			//System.out.println(type.getName());
			System.out.println(type.getSimpleName());
			
			//得到id，address的方法
			System.out.println(field.getName());
			
			//获取修饰符
			int i = field.getModifiers();
			String strModifier = Modifier.toString(i);
			System.out.println(strModifier);
		}
		
		——————————————————————————————————————————————————————————————————————————————————————
		输出常规格式：
		StringBuffer sb = new StringBuffer();
		sb.append(Modifier.toString(c.getModifiers()) + "class" + c.getSimpleName() + "{\n");
		for(Field field : fs)
		{
			sb.append("\t");
			sb.append(Modifier.toString(field.getModifiers() + " "));
			sb.append(field.getType().getSimpleName() + " ");
			sb.append(field.getName() + ";\n");
		}
		
		sb.append("}");
		
		System.out.println(sb);
	}
}

public class User
{
	private String id;
	public int age;
	protected String addr;
	boolean sex;
}

————————————————————————————————————————————————————————————————————————————————————


public class ReflectTest
{
	public static void main(String[] args) throws Exception
	{
		//获取类
		Class c = Class.forName("User");
		
		//获取id属性
		Field idF = c.getDeclaredField("id");
		
		//获取到某个特定的属性可以用来？set，get
		Object o = c.newInstance();   //创建由此 类对象表示的类的新实例。 
		
		//打破封装
		idF.setAccessible(true);  //使用反射机制打破封装性，导致java对象属性的不安全
		
		//给o对象的id属性赋值”110“
		idF.set(o, "110");
		
		//get
		System.out.println(idF.get(o));
		
	}
}


====================================================================================
/*
	java.lang.reflect.Method;
*/
  
public class CustomerService
{
	//登录
	public boolean login(String name, String pwd)
	{
		if("admin".equals(name) && "123".equals(pwd))
		{
			return true;
		}
		
		return false;
	}
	
	//退出
	public void logout()
	{
		System.out.println("系统安全退出！");
	}
}
  
import java.lang.reflect.*;

public class ReflectTest 
{
	public static void main(String[] args) throws Exception
	{
		//获取类
		Class c = Class.forName("CustomerService");
		
		//获取所有的方法
		Method[] ms = c.getDeclaredMethods();
		
		for(Method m : ms)
		{
			//修饰符 
			System.out.println(Modifier.toString(m.getModifiers()));
			
			//方法的返回值类型
			Class returnType = m.getReturnType();
			System.out.println(returnType.getSimpleName());
			
			//方法名
			System.out.println(m.getName());
			
			//方法的形式参数列表
			Class[] parameterTypes = m.getParameterTypes();
			for(Class parameterType : parameterTypes)
			{
				System.out.println(parameterType.getSimpleName());
			}
		}
		
		————————————————————————————————————————————————————————————————
		
		StringBuffer sb = new StringBuffer();
		sb.append(Modifier.toString(c.getModifiers()) + "class");
		sb.append(c.getSimpleName() + "{\n");
		
		for(Method m : ms)
		{
			sb.append("\t");
			sb.append(Modifier.toString(m.getModifiers()) + " ");
			sb.append(m.getName() + "(");
			
			//形参
			Class[] parameterTypes = m.getParameterTypes();
			for(int i = 0; i < parameterTypes.length; i++)
			{
				Class parameterType = parameterTypes[i];
				if(i == parameterTypes.length - 1)
				{
					sb.append(parameterType.getSimpleName());
				}
				else
				{
					sb.append(parameterType.getSimpleName() + ",");
				}
			}
			sb.append("){}\n");
		}
		sb.append("}");
		System.out.println(sb);
	}
}
  
————————————————————————————————————————————————————————————————————————————————————
/*
	获取某个特定的方法，通过反射机制执行
*/
  
import java.lang.reflect.*;
public class ReflectTest
{
	public static void main(String[] args) throws Exception
	{
		//获取类
		Class c = Class.forName("CustomerService");
		
		//获取某个特定的方法 
		//通过：方法名 + 形参列表
		Method m = c.getDeclaredMethod("login",String.class,String.class);
		
		//通过反射机制执行login方法
		Object o = c.newInstance();
		
		//调用c对象的m方法，传递"admin""123"参数，方法的执行结果使retValue
		//在具有指定参数的 方法对象上调用此 方法对象表示的底层方法。 
		Object retValue = m.invoke(o, "admin", "456");
		
		System.out.println(retValue); //true
	}
}
  

————————————————————————————————————————————————————————————————————————————————————

/*
	获取构造方法
*/  
  
public class reflectTest
{
	public static void main(String[] args)
	{
		//获取类
		Class c = Class.forName("java.lang.String");
		
		//获取所有的构造
		Constructor[] cs = c.getDeclaredConstructors();
		
		/*
		for(Constructor con : cs)
		{
			//获取修饰符
			System.out.println(Modifier.toString(con.getModifiers()));
			
			//获取构造方法名
			System.out.println(c.getName());
			
			//构造方法的形式参数列表
			Class[] parameterTypes = con.getParameterTypes();
			for(Class parameterType : parameterTypes)
			{
				System.out.println(parameterType.getSimpleName());
			}
		}
		*/
		
		//反编译：
		StringBuffer sb = new StringBuffer();
		
		sb.append(Modifier.toString(c.getModifiers()) + " ");
		sb.append(c.getSimpleName() + "(");
		
		//形参 
		Class[] parameterTypes = con.getParameterTypes();
		for(int i = 0 ; i < parameterTypes.length; i++)
		{
			Class parameterType = parameterTypes[i];
			if(i == parameterTypes.length - 1)
			{
				sb.append(parameterType.getSimpleName());
			}
			else
			{
				sb.append(parameterType.getSimpleName() + ",");
			}
		}
		sb.append("){}\n");
	}
	
    sb.append("}");
}
  
  
————————————————————————————————————————————————————————————————————————
/*
	获取某个特定的构造方法，然后创建对象
*/

import java.lang.reflect.*;
public class ReflectTest
{
	public static void main(String[] args) throws Exception
	{
		//获取类
		Class c = Class.forName("Customer");
		
		//获取特定的构造方法
		Constructor con = c.getDeclaredConstructor(String.class, int.class);
		
		//创建对象 
		Object o = con.newInstance("张三",25);
		
		System.out.println(o);
	}
}

class Customer
{
	String name;
	int age;
	
	Customer(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	
	public String toString()
	{
		return "Customer["+name+", "+age+"]";
	}
}


————————————————————————————————————————————————————————————————
/*
	关于类获取父类和父接口
*/


public class reflectTest10
{
	public static void main(String[] args) throws Exception
	{
		Class c = Class.forName("java.util.Date");
		
		//获取父类
		Class superClass = c.getSuperclass();
		
		System.out.println(superClass.getName());
		
		//获取父接口
		Class[] ins = c.getInterfaces();
		
		for(Class in : ins)
		{
			System.out.println(in.getName());
		}
	}
}




=====================================================================================================================



byte b = 3;  0000 0011
b = b + 2;   因为b是byte类型     2是int类型    byte可以向int转化  也就是  0000 0000 0000 0000 0000 0000 0000 0011   +    0000 0000 0000 0000 0000 0000 0000 0010
             但是b本来就是byte，无法完成赋值  所以  (byte)(b + 2)    就是砍掉前面的精度0000 0101

如果arr是一个数组
System.out.println(arr);  //输出结果[I@de6ced    [代表是一个数组I代表是数组里的元素是int类型，@后面是这个数组的地址


十进制-->十六进制
public static void toHex(int num)
{
	for(int x = 0; x < 8; x++)
	{
		int temp = num & 15;
		if(temp > 9)
			System.out.println((char)(temp - 10 + 'A'));
		else
			System.out.println(temp);
		num = num >>> 4
	}
}





class Solution {
public:
    //小数部分如果余数重复出现两次就表示该小数是循环小数了
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0) return "";//边界条件，分母为0
        if(numerator==0) return "0";//边界条件，分子为0
        string result;
        
        //转换为longlong防止溢出
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);
        
        //处理正负号，一正一负取负号
        if((num>0)^(denom>0))result.push_back('-');
        
        //分子分母全部转换为正数
        num=abs(num);denom=abs(denom);
        
        //处理整数部分
        result.append(to_string(num/denom));
        
        //处理小数部分
        num%=denom;                         //获得余数
        if(num==0)return result;             //余数为0，表示整除了，直接返回结果
        result.push_back('.');              //余数不为0，添加小数点
        int index=result.size()-1;          //获得小数点的下标
        unordered_map<int,int> record;      //map用来记录出现重复数的下标，然后将'('插入到重复数前面就好了
        while(num&&record.count(num)==0){   //小数部分：余数不为0且余数还没有出现重复数字
            record[num]=++index;
            num*=10;                        //余数扩大10倍，然后求商，和草稿本上运算方法是一样的
            result+=to_string(num/denom);
            num%=denom;
        }
        if(record.count(num)==1){           //出现循环余数，我们直接在重复数字前面添加'(',字符串末尾添加')'
            result.insert(record[num],"(");
            result.push_back(')');
        }
        return result;
    }
};

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
匿名对象
1.当对象的方法只调用一次时，可以使用匿名对象来完成，这样写比较简便(当这个方法结束时，这个匿名对象也就没有了)
2.如果对一个对象进行多个成员调用，必须给这个对象起一个名字   //如果是new，当main函数结束时，它才结束
3.可以将匿名对象进行实际参数进行传递  show(new Car()); //当show结束时，它也就结束了

———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
classPath的配置
1.class文件 就是Java运行文件 也叫中间码文件或字节码文件  只要有虚拟机，只用让别人把class文件给我发过来我就可以运行
2.Java Hello 就会去运行虚拟机
3.一个class文件只能在本路径下使用，如果想让其他地方也使用得配置classpath
set classpath=路径
C:\>set classpath=D:\java0217\day01 

对环境变量进行清空
E:\>set classpath=     //后面什么也不写，就是清空

C:\>set classpath=D:\java0217\day01;
如果有;虚拟机先去找classpath再去找当前目录
如果没有分号，直接去classpath找，如果没有就没了
一般不要加分号

如果要想前去找C盘，再去找D盘
D:java038887\set classpath=c:\;d:\

先找当前路径，再去C盘，再去D盘
D:java038887\set classpath=.;c:\;d:\   //.就代表当前路径

如果是path 现在当前目录下找，没找着，再去path指定的文件中找
如果是可执行文件path 就是qq之类
如果是java文件classpath
E:\>set path=C:\Program Files\Tencent\QQ\Bin;%path%  //%path%加上原配置
  
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
如果将.class文件发送给其他人，其他人只要将该文件设置到classpath路径下，就可以使用该工具类
但是很遗憾，该类中到底定义了多少个方法，对方并不清楚，因为该类并没有使用说明书
开始制作说明书，java的说明书通过文档注释来完成
/**
	这是一个可以对数组进行操作的工具类，该类中提供了获取最值，排序等功能
	@autor 梅宝贝
	@version v1.1
*/

class ArraysTool
{
	private ArrayTest(){}
	/**
		获取一个整型数组中的最大值
		@param arr 接受一个int类型的数组
		@return 会返回该数组的最大值0
	*/
	........
}
提取文件中的注释
D:\java0217\day01>javadoc -d myhelp      //如果当前目录下没有这个文件夹，会帮你建一个
D:\java0217\day01>javadoc -d myhelp -author -version ArrayTool.java //如果想取到作者和版本

如果一个类想生成帮助文档，必须是public修饰

生成的文档就像jdk一样，omg，如果一个类是私有的，不会写入帮助文档中，只有public才会写入到帮助文档中

/*
	一个类中默认会有一个空参数的构造函数
	这个默认的构造函数的权限和所属类一致
	如果类被public修饰，那么默认的构造函数也带public修饰符
	如果类没有被public修饰，那么默认的构造函数，也没有pbulic修饰
	
	默认构造函数的权限是随着类的变化而变化的
*/


——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

1.length：
　　是一个 属性
　　针对的是 数组
    就是普通的数组
　　得到的结果是 数组的长度
　　eg:　　String [] array = {"abc","def","ghi"};
　　　　　 System.out.println( array.length );
　　　　　 =====> 3
2.length()：
　　是一个 方法
　　针对的是 字符串
　　获取的是 字符串的长度
 
　　eg:　　String [] array = {"abc","def","ghi"};
　　　　　 String s = "abcdef";
　　　　　 System.out.println( array[0].length() );
　　　　　 System.out.println( s.length() );
　　　　　 =====> 3   6
3.size()：
　　是一个 方法
　　针对的是 泛型集合
　　获取的是 集合的元素个数
    泛型就是<>只要加<>就得用sizeof来算
　　eg:　　List<Object> list = new ArrayList();
　　　　　 list.add("aaa");
　　　　　 System.out.println( list.size() );
　　　　　 =====> 1


length是数组里有多少个元素       
length() 是"" 里面有多少个字符

====================================

//compare是java.util.Comparator<T>接口的方法  用于集合或数组中元素的比较 Collection.sort() 或者是 Array.sort()中对目标排序
//compareTo是java.lang.Comparable<T>,当需要对某个类的对象进行排序时
	
====================================
toArray方法
ArrayList提供了一个将List转为数组的一个非常方便的方法toArray。toArray有两个重载的方法：
1.list.toArray();
2.list.toArray(T[]  a);
对于第一个重载方法，是将list直接转为Object[] 数组；
第二种方法是将list转化为你所需要类型的数组，当然我们用的时候会转化为与list内容相同的类型。

String[] array =new String[list.size()];
list.toArray(array);


sort(T[] a, Comparator<? super T> c) 
根据指定的比较器引发的顺序对指定的对象数组进行排序。
Comparator中有compare方法

public int compare(Object obj1, Object obj2) 
{

	//相当于从小到大排序 大的返回正值，往后放

	return obj1.value()-obj2.value();

	//相当于从大到小排序，大值返回负值，往前放

	return -(obj1.value()-obj2.value());

}


===========================================================================================================================

Lambda表达式
1.在匿名内部类中的应用
public void test()
{
	Comparator<Integer> com = new Comparator<Integer>()
	{
		public int compare(Integer o1, Integer o2)
		{
			return Integer.compare(o1, o2);
		}
	};
	
	TreeSet<Integer> ts = new TreeSet<>(com);
}

//Lambda  表达式
public void test2()
{
	Comparator<Integer> com = (x, y) -> Integer.compare(x, y);
	TreeSet<Integer> ts = new TreeSet<>(com);
}

2.员工大于35岁
public class Employee
{
	private String name;
	private int age;
	private double salary;
	
	public Employee()
	{}
	
	public Emploee(String name, int age, double salary)
	{
		this.name = name;
		this.age = age;
		this.salary = salary;
	}
	
	public String getName()
	{
		return name;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public void setAge(int age)
	{
		this.age = age;
	}
	
	public int getAge()
	{
		return age;
	}
	
	public void setSalary(int salary)
	{
		this.salary = salary;
	}
	
	public int getSalary()
	{
		return salary;
	}
}


List<Employee> employees = Arrays.asList{
	new Employee("张三", 18, 9999.99);
	new Employee("赵四", 38, 66666.99);
	new Employee("王五", 50, 99.99);
	new Employee("赵六", 16, 933.99);
	new Employee("田七", 4, 9789.99);
};
  
//需求：获取当前公司中年龄大于35的员工信息

public List<Employee> filterEmplyees(List<Employee> List)
{
	List<Employee> emps = new ArrayList<>();
	
	for(Employee emp : lists)
	{
		if(emp.getAge() >= 35)
		{
			emps.add(emp);
		}
	}
	
	return emps;
}

如果需求变了，就会写很多类似上面的重复代码，所以下面利用接口进行优化:
//优化方式1：策略设计模式
public interface MyPredicate<T>
{
	public boolean test(T t);
}

public class TilterEmployeeByAge implements MyPredicate<Employee>
{
	public boolean test(Employee t)
	{
		return t.getAge() >= 35;
	}
}

public class FilterEmployeeBySalary implements MyPredicate<Employee>
{
	public boolean test(Employee t)
	{
		return t.getSalary() >= 5000;
	}
}

public List<Employee> filterEmployee(List<employee> list, MyPredicate<Employee> mp)
{
	List<Employee> emps = new ArrayList<>();
	
	for(Employee employee : List)
	{
		if(mp.test(employee))
		{
			emps.add(employee);
		}
	}
	
	return emps;
}


public void test4()
{
	List<Employee> list = filterEmployee(employee, new FilterEmployeeByAge());
	
	for(Employee employee : list)
	{
		System.out.println(employee);
	}
	
}

//优化方式二：匿名内部类

public void test5()
{
	List<Employee> list = filterEmployee(employees, new Mypredicate<Employee>
	{
		public boolean test(Employee t)
		{
			return t.getSalary() <= 5000;
		}
	});
	
	for(Employee employee : list)
	{
		System.out.println(employee);
	}
}

//优化方式三：Lambda 表达式
public void test6()
{
	List<Employee> List = filterEmployee(employee, (e) -> e.getSalary() <= 5000);
}


————————————————————————————————————————————————————————————————————————————————————————
优化方式四：我不懂

List<Employee> employees = Arrays.asList{
	new Employee("张三", 18, 9999.99);
	new Employee("赵四", 38, 66666.99);
	new Employee("王五", 50, 99.99);
	new Employee("赵六", 16, 933.99);
	new Employee("田七", 4, 9789.99);
};


public void test7()
{
	employee.stream()
	        .filter((e) -> e.getSalary() >= 5000)
			.forEach(System.out :: println);
}


——————————————————————————————————————————————————————

private String[] calendar = new String[] {"星期一","星期二","星期三","星期四","星期五","星期六","星期天"};


————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

public interface Subject{
	public void registerObserver(Observer o);
	public void removeObserver(Observer o);
	public void notifyObservers();
}

public interface Observer{
	public void update(float temp, float hunidity, float pressure);
}

public interface DisplayElement
{
	public void display();
}

public class WeatherData implements Subject{
	private ArrayList observers;
	private float temperature;
	private float hunidity;
	private float pressure;
	
	public WeatherData(){
		observers =new ArrayList();
	}
	
	public void registerObserver(Observer o){
		observers.add(o);
	}
	
	public void removeObserver(Observer o)
	{
		int i = Observers.indexOf(o);
		if(i >= 0)
		{
			observers.remove(i);
		}
	}
	
	public void notifyObservers()
	{
		for(int i = 0; i < observers.size(); i++)
		{
			Observer observer = (Observer)observers.get(i);
			observer.update(temperature, humidity, pressure);
		}
	}
	
	public void measurementsChanged()
	{
		notifyObservers();
	}
	
	public void setMeasurements(float temperature, float humidity, float pressure)
	{
		this.temperature = temperature;
		this.humidity = humidity;
		this.pressure = pressure;
		
		measurementsChanged();
	}
	
	//WeatherData的其它方法
}

public class CurrentConditionsDisplay implements Observer, DisplayElement{
	private float temperature;
	private float humidity;
	private Subject weatherData;
	
	public CurrentConditionDisplay(Subject weatherData)
	{
		this.weatherData = weatherData;
		weatherData.registerObserver(this);
	}
	
	public void update(float temperature, float humidity, float pressure)
	{
		this.temperature = temperature;
		this.humidity = humidity;
		display();
	}
	
	public void display()
	{
		System.out.println("Current conditions：" + temperature + "F degrees and" + humidity + "% humidity");
	}
}


public class WeatherStation{
	public static void main(String[] args)
	{
		WeatherData weatherData = new WeatherData();
		
		CurrentConditionsDisplay currentDisplay = new CurrentConditionDisplay(weatherData);
		StatisticsDisplay statisticsDisplay = new StatisticsDisplay(weatherData);
		ForecastDisplay forecastDisplay = new ForecastDisplay(weatherData);
		
		weatherData.setMeasurements(80, 65, 30.4f);
		weatherData.setMeasurements(82, 70, 29.2f);
		weatherData.setMeasurements(78, 90, 29.2f);
	}
}




//饮料
public abstract class Beverage
{
	String description = "Unknown Beverage";
	
	public String getDescription(){
		return description;
	}
	
	public abstract double cost();
}


public abstract class CondimentDecorator extends Beverage{
	public abstract String getDescription();
}

//浓缩咖啡
public class Espresso extends Beverage{
	
	public Espresso(){
		description = "Espresso";
	}
	
	public double cost(){
		return 1.99;
	}
}

//另一种饮料
public class House extends Beverage{
	public HouseBlend(){
		description = "House Blend Coffee";
	}
}

//调料代码
public class Mocha extends CondimentDecorator{
	
	Beverage beverage;
	
	public Mocha(Beverage beverage){
		this.beverage = beverage;
	}
	
	public String getDescription(){
		return beverage.getDescription() + ", Mocha";
	}
	
	public double cost(){
		return .20 + beverage.cost();
	}
}


//下订单的测试代码
public class StarbuzzCoffee{
	public static void main(String[] args)
	{
		Beverage beverage = new Espresso();
		System.out.println(beverage.getDescription() + " $" + beverage.cost());
		
		Beverage beverage2 = new DarkRoast();
		beverage2 = new Mocha(beverage2);
		beverage2 = new Mocha(beverage2);
		beverage2 = new Whip(beverage2);
		System.out.println(beverage2.getDescription() + " $" + beverage2.cost());
		
		Beverage beverage3 = new HouseBlend();
		beverage3 = new Soy(beverage3);
		beverage3 = new Mocha(beverage3);
		beverage3 = new Whip(beverage3);
		System.out.println(beverage3.getDescription() + " $" + beverage3.cost());
	}
}


//编写自己的Java I/O装饰者
//将输入流内的所有大写字符转换成小写
public class LowerCaseInputStream extends FilterInputStream{
	public LowerCaseInputStream(InputStream in)
	{
		super(in);
	}
	
	public int read() throws IOException{
		int c = super.read();
		return (c == -1 ? Character.toLowerCase((char)c));
	}
	
	public int read(byte[] b, int offset, int len) throws IOExcepion{
		int result = super.read(b, offset, len);
		for(int i = offset; i < offset + result; i++){
			b[i] = (byte)Character.toLOwerCase((char)b[i]);
		}
		return result;
	}
}

//测试类
public class InputTest{
	public static void main(String[] args) throws IOException{
		int c;
		try
		{
			InputStream in = new LowerCaseInputStream(new BufferedInputStream(new FileInputStream("test.txt")));
			while((c = in.read()) >= 0)
			{
				System.out.print((char)c);
			}
			in.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}





public abstract class Duck{
	FlyBehavior flyBehavior;
	QuackBehavior quackBehavior;
	public Duck(){
		
	}
	
	public abstract void display();
	
	public void performFly(){
		flyBehavior.fly();
	}
	
	public void performQuack(){
		quackBehavior.quack();
	}
	
	public void swim(){
		System.out.println("All ducks float, even decoys");
	}
	
	————————————————————————————————————————————————————————————
	
	public void setFlyBehavior(FlyBehavior fb){
		flyBehavior = fb;
	}
	
	public void setQuackBehavior(QuackBehavior qb){
		quackBehavior = qb;
	}
}

//所有飞行的行为必须实现的接口
public interface FlyBehavior{
	public void fly();
}

//会飞的
public class FlyWithWings implements FlyBehavior{
	public void fly(){
		System.out.println("I'm flying");
	}
}

//不会飞的
public class FlyNoWay implements FlyBehavior{
	public void fly(){
		System.out.println("I can't fly");
	}
}


//利用火箭动力的飞行
public class FlyRocketPowered implements FlyBehavior{
	public void fly(){
		System.out.println("I'm flying with a rocket!");
	}
}

//叫的接口
public interface QuackBehavior{
	public void quack();
}

public class Quack implements QuackBehavior{
	public void quack(){
		System.out.println("Quack");
	}
}

public class Squeak implements QuackBehavior{
	public void quack(){
		System.out.println("Squeak");
	}
}

public class MallardDuck extends Duck{
	public MallardDuck(){
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
	}
}

public class ModelDuck extends Duck{
	public ModelDuck(){
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	}
	
	public void display(){
		System.out.println("I'm a model duck");
	}
}

public class MiniDuckSimulator{
	public static void main(String[] args){
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		mallard.performFly();
		
		—————————————————————————————————
		
		//加上模型鸭，并使模型鸭具有火箭动力
		Duck model = new ModelDuck();
		model.performFly();
		model.setFlyBehavior(new FlyRocketPowered());
		model.performFly();
	}
}
  
  
  
  
import java.util.Observable;   //bigBoss
import java.util.Observer;     //观察者

public interface DisplayElement
{
	public void display();
}

public class WeatherData extends Observable{
	private float temperature;
	private float humidity;
	private float pressure;
	
	public WeatherData(){}
	
	public void measurementsChanged(){
		setChanged();         //在调用notifyObservers()来指示状态已经改变
		notifyObservers();    //通知观察者
	}
	
	public void setMeasurements(float temperature, float humidity, float pressure){
		this.temperature = temperature;
		this.humidity = humidity;
		this.pressure = pressure;
		
		//通知观察者
		measurementsChanged();
	}
	
	//返回数据
	public float getTemperature(){
		return temperature;
	}
	
	public float getHumidity(){
		return humidity;
	}
	
	public float getPressure(){
		return pressure;
	}
}
  
 
public class CurrentConditionDisplay implements Observer, DisplayElement{
	Observable observer;
	private float temperature;
	private float humidity;
	
	public CurrentConditionDisplay(Observable observable){
		this.observable = observable;
		observable.addObserver(this);
	}
	
	public void update(Observable obs, Object arg)
	{
		if(obs instanceof WeatherData)
		{
			WeatherData weatherData = (WeatherData)obs;
			this.temperature = temperature;
			this.humidity = humidity;
			display();
		}
	}
	
	public void display()
	{
		System.out.println("Current conditions：" + temperature + "F degrees and" + humidity + "% humidity");
	}
}
  
  
————————————————————————————————————————————————————————————————————————————————————————————————————————————

//这个类只做一件事，为它的客户创建披萨
//这个工厂可以有很多的客户：创建披萨   披萨店菜单   宅急送
//可以创建静态工厂，不需要使用创建对象的方法来实例化对象，但不能通过继承来改变创建方法的行为
public class SimplePizzaFactory{
	
	//所有客户用这个方法来实例化新对象
	public Pizza createPizza(String type){
		Pizza pizza = null;
		
		if(type.equals("cheese")){
			pizza = new Cheesepizza();
		}
		else if(type.equals("peopperoni")){
			pizza = new PepperoniPizza();
		}
		else if(type.equals("clam")){
			pizza = new ClamPizza();
		}
		else if(type.equals("veggie")){
			pizza = new VeggiePizza();
		}
		
		return pizza;
	}
}
  

public class PizzaStore{
	SimplePizzaFactory factory;
	
	public PizzaStore(SimplePizzaFactory factory){
		this.factory = factory;
	}
	
	public Pizza orderPizza(String type){
		Pizza pizza;
		
		//我们把new操作符替换成工厂对象的创建方法，这里不再使用具体实例化
		pizza = factory.createPizza(type);
		
		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();
		
		return pizza;
	}
	
	//这里是其它方法
}
  
---------------------------------------------------------------------------
public abstract class Pizza{
	String name;
	String dough;
	String sauce;
	ArrayList toppings = new ArrayList();
	
	void prepare(){
		System.out.println("Preparing" + name);
		System.out.println("Tossing dough...");
		System.out.println("Adding sauce...");
		System.out.println("Adding toppings：");
		
		for(int i = 0; i < toppings.size(); i++){
			System.out.println("   " + toppings.get(i));
		}
	}
	
	void bake(){
		System.out.println("Bake for 25 minutes at 350");
	}
	
	void cut(){
		System.out.println("Place pizza in official PizzaStore box");
	}
	
	public String getName(){
		return name;
	}
}

改良版
——————————————————————————————————————————————————————
1.每个商店继承了PizzaStore，但是可以根据自己的特色来指定createPizza()里的内容
2.工厂方法和创建者不总是抽象的



——————————————————————————————————————————————————————

//这个PizzaStore作为超类，让每个域类型(NYPizzaStore、ChicagoPizzaStore、CaliforniaPizzaStore)继承这个PizzaStore，每个子类各自决定如何制造披萨
//披萨加工厂
public abstract class PizzaStore{
	
	public Pizza orderPizza(String type){
		Pizza pizza;
		
		pizza = createPizza(type);
		
		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();
		
		return pizza;
	}
	
	abstract Pizza createPizza(String type);  //现在把工厂对象移到这个方法中
}
  
  
//本店推出的披萨种类
public MYStylePizzaStore extends PizzaStore{
	
	public Pizza createPizza(type){
		
		if(type.equals("cheese")){
			pizza = new NYStyleCheesePizza();
		}
		else if(type.equals("pepperoni")){
			pizza = new NYStylePepperoniPizza();
		}
		else if(type.equals("clam")){
			pizza = new NYStyleClamPizza();
		}
		else if(type.equals("veggie")){
			pizza = new NYStyleVeggiePizza();
		}
	}
}

//另一家店推出的披萨种类
public ChicagoStylePizzaStore extends PizzaStore{
	
	public Pizza createPizza(type){
		
		if(type.equals("cheese")){
			pizza = new ChicagoStyleCheesePizza();
		}
		else if(type.equals("pepperoni")){
			pizza = new ChicagoStylePepperoniPizza();
		}
		else if(type.equals("clam")){
			pizza = new ChicagoStyleClamPizza();
		}
		else if(type.equals("veggie")){
			pizza = new ChicagoStyleVeggiePizza();
		}
	}
} 
  
//这些种类的披萨的具体实现，继承的是Pizza
public class ChicagoStyleCheesePizza extends Pizza{
	public ChicagoStyleCheesePizza(){
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";
		
		toppings.add("Shredded Mozzarella Cheese");
	}
	
	void cut(){
		System.out.println("Cutting the pizza into square dlices");
	}	
}
  
  
public class PizzaTestDrive{
	public static void main(String[] args){
		PizzaStore nyStore = new NYPizzaStore();
		PizzaStore chicagoStore = new ChicagoPizzaStore();
		
		Pizza pizza = nyStore.orderPizza("cheese");
		System.out.println("Ethan ordered a" + pizza.getName() + "\n");
		
		pizza = chicagoStore.orderPizza("cheese");
		System.out.println("Joel ordered a" + pizza.getName() + "\n");
	}
}
  
  
工厂模式定义：
工厂模式动议了一个创建对象的接口，但由子类决定要实例化的类是哪一个。工厂方法让类把实例化推迟到子类
  
  
对象依赖：
如果所有的分店都在总店中实现，每一次分店的改变都会影响总店

依赖倒置原则：
1.设计原则：要依赖抽象，不要依赖具体类
  不能让高层组件依赖于低层组件，而且，不管高层或低层组件，两者都应该依赖于抽象 
  
例：PizzaStore依赖于Pizza   而且各种类型的披萨也依赖于Pizza
    思维过程：我需要要开一个店， 我要制作披萨，包装，还需要各种口味的披萨，所以我需要一个pizza类；回过头思考如何开店，从一个工厂里取出这些披萨
低层组件依赖于高层的抽象，而高层的抽象也依赖于这个(Pizza)
一般来说，依赖图都是从上到下的，现在反过来了

2.规则：
变量不可以持有具体类的引用
不要让类派生自具体类
不要覆盖基类中已实现的方法


//构建原料工厂
public interface PizzaIngredientFactory{
	public Dough createDough();
	public Sauce createSauce();
	public Cheese createCheese();
	public Veggies[] createVeggies();
	public Pepperoni createPepperoni();
	public Clame createClam();
} 

//创建纽约原料工厂
public class NYPizzaIngredientFactory implements PizzaIngredientFactory{
	
	public Dough createDough(){
		return new ThinCrustDough();
    }
	
	public Sauce createSauce(){
		return new MarinaraSauce();
	}
	
	public Cheese createCheese(){
		return new ReggianoCheese();
	}
	
	public Veggies[] createVeggies(){
		Veggies veggies[] = {new Garlic, new Onion(), new Mushroom(), new RedPepper()};
	}
	
	public Pepperoni createPepperoni(){
		return new SlicedPepperoni();
	}
	
	public Clams createClam(){
		return new FreashClams();
	}
}

public abstract class Pizza{
	String name;
	String dough;
	String sauce;
	Veggies veggies[];
	Cheese cheese;
	Pepperoni pepperoni;
	Clams clam;
	
	//原料的准备
	abstract void prepare();
	
	void bake(){
		System.out.println("Bake for 25 minutes at 350");
	}
	
	void cut(){
		System.out.println("Place pizza in official PizzaStore box");
	}
	
	void box(){
		System.out.println("Place pizza in official PizzaStore box");
	}
	
	public setName(String name){
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	public String toString(){
		//这里是打印披萨的代码
	}
}

public class CheesePizza extends Pizza{
	PizzaIngredientFactory ingredientFactory;
	
	public CheesePizza(PizzaIngredientFactory ingredientFactory)
	{
		this.ingredientFactory = ingredientFactory;
	}
	
	void prepare(){
		System.out.println("Preparing" + name);
		dough = ingredientFactory.createDough();
		sauce = ingredientFactory.createSauce();
		cheese = ingredientFactory.createCheese();
	}
}


//纽约的店
public class NYPizzaStore extends PizzaStore{
	
	protected Pizza createPizza(String item)
	{
		Pizza pizza = null;
		PizzaIngredientFactory ingredientFactory = new NYPizzaIngredientFactory();
		
		if(item.equals("cheese")){
			pizza = new NYStyleCheesePizza();
			pizza.setName("New York style Cheese Pizza");
		}
		else if(item.equals("pepperoni")){
			pizza = new NYStylePepperoniPizza();
			pizza.setName("New York style pepperoni Pizza");
		}
		else if(item.equals("clam")){
			pizza = new NYStyleClamPizza();
			pizza.setName("New York style clam Pizza");
		}
		else if(item.equals("veggie")){
			pizza = new NYStyleVeggiePizza();
			pizza.setName("New York style veggie  Pizza");
		}
		
		return pizza;
	}
}


PizzaStore nyPizzaStore = new NYPizzaStore();

Pizza pizza = createPizza("cheese");



————————————————————————————————————————————————————————————————
抽象工厂模式：
抽象工厂模式提供一个接口，用于创建相关或依赖对象的家族，而不需要明确指定具体类


——————————————————————————————————————————————————————————————————————————————————————————————————

单件模式：
public class Singleton{
	private static Singleton uniqueInstance;
	
	private Singleton(){}
	public static synchronized Singleton getInstance(){
		if(uniqueInstance == null){
			uniqueInstance = new Singleton();
		}
		
		return uniqueInstance;
	}
}

public class Singleton{
	private static Singleton uniqueInstance = new Singleton();
	
	private Singleton(){}
	
	public static Singleton getInstance(){
		return uniqueInstance;
	}
}
单件模式确保一个类只有一个实例，并提供一个全局访问点



——————————————————————————————————————————————————————————————————————————————————————————————————————————

命令模式
把封装调用封装起来
命令模式将“请求”封装成对象，以便使用不同的请求，队列或者日志来参数化其它对象。命令模式也支持呵撤销的操作


//让所有的命令对象都实现这个命令接口
public interface Command{
	public void excute();
	//和excute()相反的按钮
	public void undo();
}
  
public class NoCommand implements Command{
	public void excute(){}
	public void undo(){}
}
  
  
//实现一个打开电灯的命令
public class LightOnCommand implements Command{
	Light light;
	
	public LightOnCommand(Light light){
		this.light = light;
	}
	
	public void execute(){
		light.on();
	}
	
	public void undo(){
		light.off();
	}
} 
  
public class LightOffCommand implements Command{
	Light light;
	
	public LightOffCommand(Light light){
		this.light = light;
	}
	
	public void excute(){
		light.off();
	}
	
	public void undo(){
		light.on();
	}
}  
  
public class RemoteControl
{
	Command[] onCommands;
	Command[] offCommands;
	
	public RemoteControl()
	{
		onCommands = new Command[7];
		offCommands = new Commands[7];
		
		//每个插槽都预先指定成NoCommand对象，以便确定每个插槽永远都有命令对象
		Command noCommand = new NoCommand();
		for(int i = 0; i < 7; i++)
		{
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
	}
	
	public void setCommand(int slot, Command onCommand, Command offCommand)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	
	public void onButtonWasPushed(int slot)
	{
		onCommands[slot].execute();
	}
	
	public void offButtonWasPushed(int slot)
	{
		offCommands[slot].excute();
	}
	
	//覆盖toString().打印出每个插槽和它对应的命令。稍后在测试遥控器的时候，会用到这个方法
	public String toString(){
		StringBuffer StringBuff = new StringBuffer();
		StringBuff.append("\n----- Remote Control -----\n");
		for(int i = 0; i < onCommands.length; i++){
			StringBuff.append("[slot " + i + "]" + onCommands[i].getClass().getName() + "   " + offCommands[i].getClass().getName() + "\n");
		}
		return StringBuff.toString();
	}
}
  
---------------------------------------------------------------------------------------------------------------------------------------------

public class RemoteControlWithUndo{
	Command[] onCommands;
	Command[] offCommands;
	//记录前一个命令是什么
	Command undoCommand;
	
	public RemoteControlWithUndo(){
		onCommands = new Command[7];
		offCommands = new Commands[7];
		
		//每个插槽都预先指定成NoCommand对象，以便确定每个插槽永远都有命令对象
		Command noCommand = new NoCommand();
		for(int i = 0; i < 7; i++)
		{
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
		
		undoCommand = noCommand;
	}
	
	public void setCommand(int slot, Command onCommand, Command offCommand)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	
	public void onButtonWasPushed(int slot){
		onCommands[slot].execute();
		undoCommand = onCommands[slot];
	}
	
	public void offButtonWasPushed(int slot){
		offCommands[slot].excute();
		undoCommand = offCommands[slot];
	}
	
	//当按下撤销按钮，我们调用undoCommand实例变量的undo()方法，就可以倒转前一个命令
	public void undoButtonWasPushed(){
		undoCommand.undo();
	}
	
	//覆盖toString().打印出每个插槽和它对应的命令。稍后在测试遥控器的时候，会用到这个方法
	public String toString(){
		StringBuffer StringBuff = new StringBuffer();
		StringBuff.append("\n----- Remote Control -----\n");
		for(int i = 0; i < onCommands.length; i++){
			StringBuff.append("[slot " + i + "]" + onCommands[i].getClass().getName() + "   " + offCommands[i].getClass().getName() + "\n");
		}
		return StringBuff.toString();
	}
}



public class StereoOnWithCDCommand implements Command{
	Stereo stereo;
	
	public StereoOnWithCDCommand(Stereo stereo){
		this.stereo = stereo;
	}
	
	public void execute(){
		stereo.on();
		stereo.setCD();
		stereo.setVolume(11);
	}
}
  
  
public class RemoteLoader{
	public static void main(String[] args){
		RemoteControl remoteComtrol = new RemoteControl();

		//将所有装置创建在合适的位置上
		Light livingRoomLight = new Light("Living Room");
		Light kitchenLight = new Light("Kitchen");
		CeilingFan ceilingFan = new CeilingFan("Living Room");
		GarageDoor garageDoor = new GarageDoor("");
		Stereo stereo = new Stereo("Living Room");
		
		//创建所有的电灯命令对象
		LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
		LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);
		
		LightOnCommand kitchenLightOn = new LightOnCommand(kitchenLight);
		LightOffCommand kitchenLightOff = new LightOffCommand(kitchenLight);
		
		//创建吊扇的开与关命令
		CeilingFanOnCommand ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
		CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceiliingFan);
		
		//创建车库门的上与下命令
		GarageDoorUpCommand garageDoorUp = new GarageDoorUpCommand(garageDoor);
		GarageDoorDownCommand garageDoorDown = new GarageDoorDownCommand(garageDoor);
		
		//创建音响的开与关命令
		StereoOnWithCDCommand stereoOnWithCD = new StereoOnWithCDCommand(stereo);
		StereoOnWithCDCommand stereoOff = new StereOffCommand(stereo);
		
		//将这些加载到遥控器槽中
		remoteComtrol.setCommand(0, livingRoomLightOn, livingRoomLightOff);
		remoteComtrol.setCommand(1, kitchenLightOn, kitchenLightOff);
		remoteComtrol.setCommand(2, ceilingFanOn, ceilingFanOff);
		remoteComtrol.setCommand(3, stereoOnWith, stereoOff);
		
		//打印出每个遥控器偶的插槽和它被指定的命令
		System.out.pritnln(remoteComtrol);
		
		//逐步按下每个插槽的开与关按钮
		remoteComtrol.onButtonWasPushed(0);
		remoteComtrol.offButtonWasPushed(0);
		remoteComtrol.onButtonWasPushed(1);
		remoteComtrol.offButtonWasPushed(1);
		remoteComtrol.onButtonWasPushed(2);
		remoteComtrol.offButtonWasPushed(2);
		remoteComtrol.onButtonWasPushed(3);
		remoteComtrol.offButtonWasPushed(3);
		
		
		--------------------------------------------------------------------------------
		
		
		RemoteControlWithUndo remoteControl = new RemoteControlWithUndo();
		
		Light livingRoomLight = new Light("Living Room");
		
		LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
		
		LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);
		
		remoteControl.setCommand(0, livingRoomLightOn, LivingRoomLightOff);
		
		//打开台灯，关闭台灯，然后撤销
		remoteComtrol.onButtonWasPushed(0);
		remoteComtrol.offButtonWasPushed(0);
		System.out.println(remoteControl);
		remoteControl.undoButtonWasPushed();
		
		remoteComtrol.onButtonWasPushed(0);
		remoteComtrol.offButtonWasPushed(0);
		System.out.println(remoteControl);
		remoteControl.undoButtonWasPushed();
	}
}
  

——————————————————————————————————————————————————————————————————————————————————————————

使用状态实现撤销
public class CeilingFan{
	public static int HIGH = 3;
	public static int MEDIUM = 2;
	public static int LOW = 1;
	public static int OFF = 0;
	String location;    //安装的位置
	int speed;          //速度
	
	public CeilingFan(String location){
		this.location = location;
		speed = OFF;
	}
	
	public void high(){
		speed = HIGH;
		//设置高转速
	}
	
	public void medium(){
		speed = MEDIUM;
	}
	
	public void low(){
		speed = LOW;
	}
	
	public void off(){
		speed = OFF;
	}
	
	public int getSpeed(){
		return speed;
	}
}  
  
  

//加入撤销到吊扇的命令类
public class CeilingFanHighCommand implements Command{
	CeilingFan ceilingFan;
	
	//增加局部状态以便追踪吊扇之前的速度
	int prevSpeed;
	
	public CeilingFanHighCommand(CeilingFan ceilingFan){
		this.ceilingFan = ceilingFan;
	}
	
	public void excute(){
		
		//在改变吊扇的速度之前，需要先将它之前的状态记录下来，以便需要撤销时使用
		prevSpeed = ceilingFan.getSpeed();
		ceilingFan.high();
	}
	
	//将吊扇的速度设置回之前的值，达到撤销的目的
	public void undo()
	{
		if(prevSpeed == CeilingFan.HIGH){
			ceilingFan.high();
		}
		else if(prevSpeed == CeilingFan.MEDIUM){
			ceilingFan.medium();
		}
		else if(prevSpeed == CeilingFan.LOW){
			ceilingFan.low();
		}
		else if(prevSpeed == CeilingFan.OFF){
			ceilingFan.off();
		}
	}
}
  
public class RemoteLoader{
	public static void main(String[] args)
	{
		//创建了一个遥控器
		RemoteControlWithUndo remoteControl = new RemoteControlWithUndo();
		CeilingFan ceilingFan = new CeilingFan("Living Room");
		
		//在这里实例化了三个命令，分别是：高速、中速、关闭
		CeilingFanMediumCommand ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
		CeilingFanHighCommand ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
		CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceilingFan);
		
		//将中速设置到第0号插槽，将高速设置到第1号插槽，并加载这两个插槽的命令关闭
		remoteControl.setCommand(0, ceilingFanMedium, ceilingFanOff);
		remoteControl.setCommand(1, ceilingFanHigh, ceilingFanOff);
		
		remoteComtrol.onButtonWasPushed(0);   //以中速开启吊扇
		remoteComtrol.offButtonWasPushed(0);  //然后关闭
		System.out.pritnln(remoteComtrol);    //开启高速
		remoteComtrol.undoButtonWasPushed():  //撤销
		
		remoteComtrol.onButtonWasPushed(1);   //开启高速
		System.out.println(remoteControl);
		remoteControl.undoButtonWasPushed();  //撤销
	}
}
  
  
------------------------------------------------------------------------------------------------

宏命令
//按下这个按钮，所有的操作都会执行，电扇会开，灯会开
public class MacroCommand implements Command
{
	Command[] commands;
	
	public MacroCommand(Command[] commands){
		this.commands = commands;
	}
	
	public void excute(){
		for(int i = 0; i < commands; i++){
			commands[i].execute();   //当这个宏命令被遥控器执行时，就一次性执行数组里的每个命令
		}
	}
}
  
Light light = new Light("Living Room");
TV tv = new TV("Living Room"):
Stereo stereo = new Stereo("Living Room");
Hottub hottub = new Hottub();

LightOnCommand lightOn = new LightOnCommand(light);
StereoOnCommand stereoOn = new StereoOnCommand(stereo);
TVOnCommand tvOn = new TVOnCommand(tv);
HottubOnCommand hottubOn = new HottubOnCommand(hottub);

Command[] partyOn = {lightOn, stereoOn, tvOn, hottubOn};
Command[] partyOff = {lightOff, stereoOff, tvOff, hottubOff};

MacroCommand partyOnMacro = new MacroCommand(partyOn);
MacroCommand partyOffMacro = new MacroCommand(partyOff);

//将宏命令指定给一个按钮
remoteControl.setCommand(0, partyOnMacro, partyOffMacro);

//按下一些按钮，测试是否可以正常工作
System.out.println(remoteControl);
System.out.println("===Pushing Macro On===");
remoteControl.onButtonWasPushed(0);
System.out.println("===Pushing Macro Off===");
remoteControl.offButtonWasPushed(0);



——————————————————————————————————————————————————————————————————

适配器：
适配者模式将一个类的接口，转换成客户期望的另一个接口，适配器让原本接口不兼容的类可以合作无间
客户使用适配器的过程如下：
1.客户通过目标接口调用适配器的方法对适配器发出请求
2.适配器使用被适配者接口把请求转换成被适配者的一个或多个调用接口
3.客户接收到调用的结果，但并未察觉这一切是适配器起转换作用

public interface Duck{
	public void quack();
	public void fly();
}

//绿头鸭
public class MallardDuck implements Duck{
	public void quack(){
		System.out.println("Quack");
	}
	
	public void fly(){
		System.out.println("I'm flying");
	}
}
  
public interface Turkey{
	public void gobble();
	public void fly();
}  
  
public class WildTurkey implements Turkey{
	public void gobble(){
		System.out.println("Gobble gobble");
	}
	
	public void fly(){
		System.out.println("I'm flying a short distance");
	}
}
  
//假设却鸭子对象，想用一些火鸡来冒充，因为火鸡的接口不同，所以不能直接使用
public class TurkeyAdapter implements Duck{
	Turkey turkey;
	
	public TurkeyAdapter(Turkey turkey){
		this.turkey = turkey;
	}
	
	public void quack(){
		turkey.gobble();
	}
	
	//火鸡飞行距离很短，所以飞五次，看起来长
	public void fly(){
		for(int i = 0; i < 5; i++){
			turkey.fly();
		}
	}
} 
  
public class DuckTestDrive{
	public static void main(String[] args)
	{
		//创建一只鸭子
		MallardDuck duck = new MallardDuck();
		
		//创建一只火鸡
		WildTurkey turkey = new WildTurkey();
		//然后将火鸡包装进一个火鸡适配器中，使它看起来像一只鸭子
		Duck turkeyAdapter = new TurkeyAdapter(turkey);
		
		System.out.println("The Turkey says...");
		turkey.gobble();     //测试这只火鸡，让它咕咕叫
		turkey.fly();        //让它飞行
		
		System.out.println("\nThe Duck says...");
		testDuck(duck);      //测试这只鸭子
		
		System.out.println("\nThe TurkeyAdapter says...");
		testDuck(turkeyAdapter);    //传入一个假装是鸭子的火鸡
	}
	
	static void testDuck(Duck duck){
		duck.quack();
		duck.fly();
	}
}
  

对象适配器和类适配器
1.类适配器不是使用组合来适配被适者，而是继承被适配者和目标类（但是只有多重继承才可以实现）
2.对象适配器使用的是组合，类适配器使用的是继承

public class EnumerationIterator implements Iterator{
	Enumeration enum;
	
	public EnumerationIterator(Enumeration enum){
		this.enum = enum;
	}
	
	public boolean hasNext(){
		return enum.nextElement();
	}
	
	public void remove(){
		throw new UnsupportedOperationException();
	}
}
  

外观模式：改变接口的原因是为了简化接口，之所以这么称呼，是因为它将一个或数个类的复杂的一切都隐藏在背后，只显露出一个干净美好而外观
装饰者：不改变接口，但加入责任
适配器：将一个接口转化成另一个接口

外观模式提供了一个统一的接口，用来访问子系统中的一群接口。外观定义了一个高层接口，让子系统更容易访问

构造家庭影院外观
public class HomeTheaterFacade{
	//组合，将我们用到的子系统组件全部安装在这里
	Amplifier amp;
	Tuner tuner;
	DvdPlayer dvd;
	CdPlayer cd;
	Projector projector;
	TheaterLights lights;
	Screen screen;
	PopcornPopper popper;
	
	public HomeTheaterFacade(Amplifier amp,
	                        Tuner tuner;
							DvdPlayer dvd;
							CdPlayer cd;
							Projector projector;
							TheaterLights lights;
							Screen screen;
							PopcornPopper popper;){
		this.amp = amp;
		this.tuner = tuner;
		this.dvd = dvd;
		this.cd = cd;
		this.projector = projector;
		this.screen = screen;
		this.lights = lights;
		this.popper = popper;
	}
	
	public void watchMovie(String movie){
		System.out.println("Get ready to watch a movie...");
		popper.on();
		popper.pop();
		lights.dim(10);
		screen.down();
		projector.on();
		projector.wideScreenMode();
		amp.on();
		amp.setDvd(dvd);
		amp.setSurroundSound();
		amp.setVolume(5);
		dvd.on();
		dvd.play(movie);
	}
	
	public void endMovie(){
		System.out.println("Shutting movie theater down...");
		popper.off();
		lights.on();
		screen.up();
		projector.off();
		amp.off();
		dvd.stop();
		dvd.eject();
		dvd.off();
	}
}  
  
public class HomeTheaterTestDrive{
	public static void main(String[] args){
		HomeTheaterFacade homeTheater = new HomeTheaterFacade(amp, tuner, dvd, cd, projector, screen, lights, popper);
		homeTheater.watchMovie("Raiders of the Lost Ark");
		homeTheater.endMovie();
	}
}  
  
  
设计原则：最少知识原则：只和你的密友谈话
如何不要赢得太多的朋友和影响太多的对象
在对象的方法内，我们只应该调用属于以下范围的方法：
该对象本身
被当做方法的参数而传递进来的对象
此方法所创建或实例化的任何对象
对象的任何组件

//不采用这个方法
public float getTemp(){
	
	//我们从气象站取得了温度计对象，然后再从温度计对象取得温度
	Thermometer thermometer = station.getThermometer();
	return thermometer.getTemperature();
}
  
//采用这个原则
public float getTemp(){
	return station.getTemperature(); //在气象站中加入一个方法，用来向温度计请求气温，这可以减少我们所依赖的类的数目
}
  
  
--------------------------------------------------------------------------------------------------------------------


将方法调用保持在界限内.....
public class Car{
	Engine engine;      //这是一个类的组件，我们能够调用它的方法
	
	public Car(){
		//初始化发动机
	}
	
	public void start(Key key){
		Doors doors = new Doors();
		
		boolean authorized = key.turns();
		if(authorized){
			engine.start();      //可以调用对象组建的方法
			updateDashboardDisplay();    //可以调用同一个对象的本地方法
			doors.lock();      //可以调用你所创建或实例化对象的方法          
		}
	}
	
	public void updateDashboardDisplay(){
		//更新显式
	}
}  
  
  
——————————————————————————————————————————————————————————————————————————————————


模板方法模式


public class Coffee{
	void prepareRecipe(){
		boilWater();
		brewCoffeeGrinds();
		pourInCup();
		addSugarAndMilk();
	}
	
	public void boilWater(){
		System.out.println("Boiling water");
	}
	
	public void brewCoffeeGrinds(){
		System.out.println("Dripping Coffee through filter");
	}
	
	public void pourInCup(){
		System.out.println("Pouring into cup");
	}
	
	public void addSugarAndMilk(){
		System.out.println("Adding Sugar and Milk");
	}
}
 

public class Tea{
	
	void prepareRecipe(){
		boilWater();
		steepTeaBag();
		pourIncup();
		addLemon();
	}
	
	public void boilWater(){
		system.out.println("Boiling water");
	}
	
	public void steepTeaBag(){
		system.out.println("Steeping the tea");
	}
	
	public void addLemon(){
		system.out.println("Adding Lemon");
	}
	
	public void pourInCup(){
		system.out.println("Pouring into cup");
	}
} 
  
-------------------------------------------------

模板方法模式在一个方法中定义了一个算法的骨架，而将一些步骤延迟到子类中，模板方法使得子类可以在不改变算法结构的情况下，重新定义算法中的某些步骤

public abstract class CaffeineBeverage{
	
	final void prepareRecipe(){
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}
	
	abstract void brew();
	abstract void addCondiments();
	
	void boilWater(){
		system.out.println("Boiling water");
	}
	
	void pourInCup(){
		system.out.println("Pouring into cup");
	}
}
  
  
public class Tea extends CaffeineBeverage{
	public void brew(){
		system.out.println("Steeping the tea");
	}
	
	public void addCondiments(){
		system.out.println("Adding Lemon");
	}
}  
  
  
public class Coffee extends CaffeineBeverage{
	public void brew(){
		system.out.println("Dripping Coffee through filter");
	}
	
	public void addCondiments(){
		System.out.println("Adding Sugar and Milk");
	}
}
  
  
--------------------------------------------------------------------

对模板方法进行挂钩
子类必须实现这个方法，用抽象方法
是可选的，就用钩子

public abstract class CaffeineBeverageWithHook{
	void prepareRecipe(){
		boilWater();
		brew();
		pourInCup();
		if(customerWantsCondiments()){   //如果顾客想要调料，才会调用
			addCondiments();  
		}
	}
	
	abstract void brew();
	abstract void addCondiments();
	
	void boilWater(){
		system.out.println("Boiling water");
	}
	
	void pourInCup(){
		system.out.println("Pouring into cup");
	}
	
	boolean customerWantsCondiments(){   //这就是一个钩子，子类可以覆盖这个方法，但不见得一定要这么做
		return true;
	}
}
  
//使用钩子
public class CoffeeWithHook extends CaffeineBeverageWithHook{
	public void brew(){
		system.out.println("Dripping Coffee through filter");
	}
	
	public void addCondimnets(){
		system.out.println("Adding Sugar and Milk");
	}
	
	//覆盖了这个钩子，提升了自己的功能
	public boolean customerWantsCondiments(){
		String answer = getUserInput();
		
		if(answer.toLowerCase().startsWith("y")){
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private String getUserinput(){
		String answer = null;
		
		System.out.println("Would you like milk and suger with your coffee (y/n)");
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try{
			answer = in.readLine();
		}
		catch(IOExcepiton ioe)
		{
			System.out.orintln("IO error trying to read your answer");
		}
		if(answer == null)
		{
			return "no';
		}
		
		return answer;
	}
} 
  
  
public class BeverageTestDrive{
	public static void main(String[] args)
	{
		TeaWithHook teaHook = new TeaWithHook();
		CoffeeWithHook coffee = new CoffeeWithHook();
		
		system.out.println("\nMaking tea...");
		teaHook.prepareRecipe();
		
		system.out.println("\nMaking coffee...");
		coffeeHook.prepareRecipe();
	}
}  
  
----------------------------------------------------------------------

好莱坞原则
1.别调用我们，我们会调用你

用模板方法排序
public static void sort(Object[] a){
	Object aux[] = (Object[])a.clone();
	mergeSort(aux, a, 0, a.length, 0);
} 
  
private static void mergeSort(Object src[], Object dest[], int low, int high, int off)
{
	for(int i = low; i < high; i++)
	{
		for(int j = i; j > low && ((Comparable)dest[j - 1]).compareTo((Comparable)dest[j]) > 0; j--)
		{
			swap(dest, j, j - 1);
		}
	}
	
	return;
}  
  

public class Duck implements Comparable{
	String name;
	int weight;
	
	public Duck(String name, int weight){
		this.name = name;
		this.weight = weight;
	}
	
	public String toString(){
		return name + "weights" + weight;
	}
	
	public int compareTo(Object object){
		Duck otherDuck = (Duck)object;
		
		if(this.weight < otherDuck.weight)
		{
			return -1;
		}
		else if(this.weight == otherDuck.weight)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
} 
  
  
public class DuckSortTestDrive{
	public static void main(String[] args)
	{
		Duck[] ducks = {
			new Duck("Daffy", 8),
			new Duck("Dewey", 2),
			new Duck("Howard", 7),
			new Duck("Louie", 2),
			new Duck("Donald", 10),
			new Duck("Huey", 2),
		};
		
		System.out.println("Before sorting:");
		display(ducks);
		
		Arrays.sort(ducks);
		System.out.println("\nAfter sorting");
		display(ducks);
	}
	
	public static void display(Duck[] ducks){
		for(int i = 0; i < ducks.length; i++){
			System.out.println(duck[i]);
		}
	}
}  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  