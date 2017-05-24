public class fmythread extends Thread{
	public double w2;
	
	fmythread (String s){
		super();
	}
	
	public void run(){	
		double time1,time2,time3;
		time1=System.currentTimeMillis();
		System.out.println("flops loop call start");
		flopsloop();
		System.out.println("flops loop call end");
		time2=System.currentTimeMillis();
		time3=time2-time1;
		System.out.println("time = "+time3);
		double finalfloptime=time3/1000;
		double FLOPS= (4*flops.c*10000000000l)/finalfloptime;
		double GFLOPS=FLOPS/1000000000;
		System.out.println("GFLOPS: "+ GFLOPS);
	}
	
	public  void flopsloop(){
		w2=5.75;
		System.out.println("loop start");

		for(long i=0;i<1000000000l;i++){
			w2=w2+2.598;
			w2=w2-1.67;
			w2=w2+3.68;
			w2=w2-1.995;
		}
		System.out.println("loop end");

	}
}

