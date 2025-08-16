#include"Stack.cpp" 
#include<fstream>
#include<math.h>

class Maze{
	private:
		//i为输入坐标，o为输出坐标 
		int ix;
		int iy;
		int ox;
		int oy;
		//M为行，N为列(长度)。 
	    int M;
	    int N;
		int**maze; 
		Box*path;
	public:
		Maze(int inx,int iny,int outx,int outy);
		float getmin(float a,float b,float c,float d);
		bool wayout();
		~Maze();
};

Maze::Maze(int inx=1,int iny=1,int outx=3,int outy=3){
	ix=inx;
	iy=iny;
	ox=outx;
	oy=outy;
	fstream infile,outfile;
	infile.open("C:\\Users\\Tim\\Desktop\\datastructure\\Stack\\maze.txt",ios::in);
	if(!infile){
		cout<<"Input failed"<<endl;
		abort();
	}
	infile>>M>>N;
	if(ox>M-2||oy>N-2){
		cout<<"wrong end"<<endl;
		abort();
	} 
	//二维数组初始化方法 
	maze=new int*[N];
	for(int j=0;j<N;j++){
		maze[j]=new int[M];
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			infile>>maze[i][j];
		}
	}
	infile.close();
	path=new Box[M*N];
}

float Maze::getmin(float a,float b,float c,float d){
	float smaller_1=a<=b?a:b;
	float smaller_2=c<=d?c:d;
	float smallest=smaller_1<=smaller_2?smaller_1:smaller_2;
	return smallest;
}

bool Maze::wayout(){
	bool find;
	Box e(ix,iy,-1);//出发点先入栈 
	Box temp;
	Stack s(M*N);
	s.Push(e);
	int topx,topy,topd;
	int tempx,tempy,tempd;
	int right_x,right_y;
	int down_x,down_y;
	int left_x,left_y;
	int up_x,up_y;
	float min_dis;
	float dis[4];
	maze[ix][iy]=-1;
	while(!s.isEmpty()){
		e=s.GetTop();
		topx=e.i;
		topy=e.j;
		topd=e.d;
        if(topx==ox&&topy==oy){
        	cout<<"Here is the way out"<<endl;
        	int k=0;
        	while(!s.isEmpty()){
        		s.Pop(temp);
        		path[k]=temp;
        		k++;
			}
			k--;
			cout<<"the length of the path is "<<k<<endl;
			while(k>=0){
				cout<<"("<<path[k].i<<","<<path[k].j<<") "<<endl;
				k--;
			}
			return true;
		}
		find=false;
		
		right_x=topx+1;
		right_y=topy;
		dis[0]=(right_x-ox)*(right_x-ox)+(right_y-oy)*(right_y-oy)+s.Length()-1;
			
	    down_x=topx;
		down_y=topy+1;
		dis[1]=(down_x-ox)*(down_x-ox)+(down_y-oy)*(down_y-oy)+s.Length()-1;
			
	    left_x=topx-1;
		left_y=topy;
		dis[2]=(left_x-ox)*(left_x-ox)+(left_y-oy)*(left_y-oy)+s.Length()-1;
			
	    up_x=topx;
		up_y=topy-1;
		dis[3]=(up_x-ox)*(up_x-ox)+(up_y-oy)*(up_y-oy)+s.Length()-1;
		
		
		while(topd<4&&!find){
			//A star
			min_dis=getmin(dis[0],dis[1],dis[2],dis[3]);
			
			if(min_dis==dis[0]) topd=0;
			if(min_dis==dis[1]) topd=1;
			if(min_dis==dis[2]) topd=2;
			if(min_dis==dis[3]) topd=3;
			
			//topd取值0,1,2,3分别表示在上一个点的右，下，左，上面 
			switch(topd){
				case 0:tempx=topx+1;tempy=topy;break;
				case 1:tempx=topx;tempy=topy+1;break;
				case 2:tempx=topx-1;tempy=topy;break;
				case 3:tempx=topx;tempy=topy-1;break;
			}
			
			if(maze[tempx][tempy]==0) find=true;
			else dis[topd]=INFINITY;
			
			if(dis[0]==0&&dis[1]==0&&dis[2]==0&&dis[3]==0) break;
			//cout<<topd<<endl;
			//cout<<dis[0]  <<dis[1]  <<dis[2]  <<dis[3]<<endl;
			cout<<topd<<","<<dis[topd]<<endl;
		}
		
		
		if(find){
			(s.GetTop()).d=topd;
			e.i=tempx;
			e.j=tempy;
			e.d=-1;
			s.Push(e);
			maze[tempx][tempy]=-1;
			//已经走过的路置为-1，避免再回来，陷入死循环 
		}
		else{
			s.Pop(e);
			maze[e.i][e.j]=0;
			//出栈时重新置零 
		}
	}
	return false;
}

Maze::~Maze(){
	for(int i=0;i<N;i++){
		delete[] maze[i];
	}
	delete[] maze;
	delete[] path;
}

int main(){
	Maze m(1,1,8,8);
	m.wayout();
	return 0;
}
