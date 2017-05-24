public class imythread extends Thread{
	public int w1;
	
	
	imythread (String s){
		super();
	}
	
	public void run(){	
		double time1,time2,time3;
		time1=System.currentTimeMillis();
		System.out.println("iops loop call start");
		iopsloop();
		System.out.println("iops loop call end");
		time2=System.currentTimeMillis();
		time3=time2-time1;
		System.out.println("time = "+time3);
		double finaliopstime=time3/1000;
		double IOPS= (4*iops.c*100000000l)/finaliopstime;
		double GIOPS=IOPS/1000000000;
		System.out.println("GIOPS: "+ GIOPS);	
	}
	
	public  void iopsloop(){
		w1=0;
		System.out.println("loop start");

		for(long i=0;i<100000000l;i++){
			w1=w1+1;
			w1=w1-1;
			w1=w1+1;
			w1=w1-1;
		}
		System.out.println("loop end");
	}
}
