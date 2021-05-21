# PyTorch on WINDOWS 10

## Prerequirements
1.NVIDIA GPU driver
2.CUDA toolkit
3.CUDNN library
4.Python x.x
4.conda or other virtual environment (optional)

## Create new conda virtual invoronment (optional)
```
conda create -n yourenvname python=x.x anaconda
```
yourenvname: can be anything.
python=x.x: choose right python version 
Example  
```
conda create -n pytorch_env python=3.9 anaconda
```

After creating a virtual environment now we need to activate it using

```
conda activate yourenvname
```

## Install PyTorch 
1. Go to pytorch website [https://pytorch.org/] or previous versions [https://pytorch.org/get-started/previous-versions/]. 

![alt text](https://github.com/martianvenusian/installations/blob/master/PyTorch/pytorch_download_01.jpg?raw=true)

Choose right version according to your CUDA version

2. Install pytorch

```
# CUDA 11.0
conda install pytorch==1.7.1 torchvision==0.8.2 torchaudio==0.7.2 cudatoolkit=11.0 -c pytorch
```