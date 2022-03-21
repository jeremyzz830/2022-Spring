""" Model classes defined here! """

import torch
import torch.nn.functional as F

class FeedForward(torch.nn.Module):
    def __init__(self, hidden_dim):
        """
        In the constructor we instantiate two nn.Linear modules and 
        assign them as member variables.
        """
        super(FeedForward, self).__init__()
        self.linear1 = torch.nn.Linear(28*28, hidden_dim)
        self.linear2 = torch.nn.Linear(hidden_dim, 8)

    def forward(self, x):
        """
        Compute the forward pass of our model, which outputs logits.
        """
        # TODO: Implement this!
        output1=self.linear1(x)
        activ=F.relu(output1)
        output2=self.linear2(activ)
        return output2
        #raise NotImplementedError()

class SimpleConvNN(torch.nn.Module):
    def __init__(self, n1_chan, n1_kern, n2_kern):
        super(SimpleConvNN, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, n1_chan, kernel_size=n1_kern)
        self.conv2 = torch.nn.Conv2d(n1_chan, 8, kernel_size=n2_kern, stride=2)
        """self.conv1 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=1,
                            out_channels=n1_chan,
                            kernel_size=n1_kern),
            torch.nn.ReLU()
        )
        self.conv2 = torch.nn.Sequential(
            torch.nn.Conv2d(n1_chan,8,kernel_size=n2_kern, stride=2),
            torch.nn.ReLU()
        )   """
        
    def forward(self, x):
        # TODO: Implement this!
        batch_size=x.size(0)
        #x=x.unsqueeze(1)
        #x=x.unsqueeze(3)
        x=x.reshape(batch_size,1,28,28)
        output1=self.conv1(x)
        output2=F.relu(output1)
        output3=self.conv2(output2)
        output4=F.relu(output3)
        max_out=F.max_pool2d(output4,kernel_size=5, stride=2)
        out=max_out.view(batch_size,-1)
        return out
        #raise NotImplementedError()

class BestNN(torch.nn.Module):
    # TODO: You can change the parameters to the init method if you need to
    # take hyperparameters from the command line args!
    def __init__(self,n1_chanels,n1_k,n2_chanels,n3_chanels,n4_chanels,n2_k,n3_k,n4_k):
        super(BestNN, self).__init__()
        # TODO: Implement this!
        self.conv1 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=1,
                            out_channels=n1_chanels,
                            kernel_size=n1_k,
                            stride=2,
                            padding=1),
            torch.nn.BatchNorm2d(n1_chanels),
            torch.nn.ReLU()
        )
        self.conv2 = torch.nn.Sequential(
            torch.nn.Conv2d(n1_chanels,n2_chanels,n2_k,2,1),
            torch.nn.BatchNorm2d(n2_chanels),
            torch.nn.ReLU()
        )
        self.conv3 = torch.nn.Sequential(
            torch.nn.Conv2d(n2_chanels,n3_chanels,n3_k,2,1),
            torch.nn.BatchNorm2d(n3_chanels),
            torch.nn.ReLU()
        )
        
        self.conv4 = torch.nn.Sequential(
            torch.nn.Conv2d(n3_chanels,n4_chanels,n4_k,2,0),
            torch.nn.BatchNorm2d(n4_chanels),
            torch.nn.ReLU()
        )
        self.mlp1 = torch.nn.Linear(n4_k*n4_k*n4_chanels,40)
        self.mlp2 = torch.nn.Linear(40,8)
        
        #raise NotImplementedError()

    def forward(self, x):
        # TODO: Implement this!a
        x = x.reshape(x.size(0),1,28,28)
        x = self.conv1(x)
        x = self.conv2(x)
        x = self.conv3(x)
        x = self.conv4(x)
        x = self.mlp1(x.view(x.size(0),-1))
        x = self.mlp2(x)
        return x
        #raise NotImplementedError()
