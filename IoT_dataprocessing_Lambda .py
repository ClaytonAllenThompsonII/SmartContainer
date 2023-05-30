# **Implementing Lambda functions:**
# Create AWS Lambda functions to process and transform the incoming IoT data.
# Configure the Lambda functions to listen for IoT Core messages and perform desired operations.
# Transform the data into a suitable format for storage and further processing.


# Import packages
import boto3
import json
import time
from datetime import datetime

# A low-level client representing Amazon Simple Storage Service (S3)
s3 = boto3.resource('s3')

def labmda_handler(event, context): 