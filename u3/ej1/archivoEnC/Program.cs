using System;

public class Queue{

    private int front;
    private int rear;
    private double[] arr;

    public Queue(int size){

        front = 0;
        rear = 0;
        arr = new double[size];
    }

    public int size(){
        return (rear - front);
    }

    public void enqueue(double item) {
        arr[rear] = item;
        rear++;
    }

    public double dequeue() {
        double item = arr[front];
        front++;
        return item;
    }
}

class Program {
    static void Main() {
        Queue q = new Queue(10);
        q.enqueue(6.5);
        q.enqueue(1.3);
        q.enqueue(2.4);
        Console.WriteLine(q.dequeue());
        Console.WriteLine(q.dequeue());
        Console.WriteLine(q.dequeue());
    }
}