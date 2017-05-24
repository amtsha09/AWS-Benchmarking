import java.util.Scanner;

public class iops {
	public static int c;
	public static void main(String[] args){
		long w=0;
		Scanner sc=new Scanner(System.in);
		String choice="";

//---------------------------------------------------------------JVM warmup----------------------------------------------
		System.out.println("warm up STARTS");
		for(long i=0;i<1000000000l;i++){
			w=w+2+i;
			w=w-1;
		}
		System.out.println("warm up ENDS\n\n");
	
		do{
			System.out.println("Please select your choice: \n1. Single thread\n2. Two thread\n4. Four thread");
			c=sc.nextInt();
			switch(c){
				
				case 1: 
					for(int i=1;i<=1;i++){
						imythread threadjob=new imythread("thread"+i);	
						threadjob.start();
					}	
					break;
						
				case 2:
					for(int i=2;i<=3;i++){
						imythread threadjob=new imythread("thread"+i);	
						threadjob.start();
					}	
					break;
					
				case 4:
					for(int i=4;i<=7;i++){
						imythread threadjob=new imythread("thread"+i);	
						threadjob.start();
					}	
					break;
					
				default:
					System.out.println("Enter correct choice");
					break;
			}
						
						System.out.println("Continue(Y/N)");
						choice=sc.next();
			
		}while(choice.equals("y")||choice.equals("Y"));
	}
}
