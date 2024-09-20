from PIL import Image
import os
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
import joblib

class LogisticRegressionClassifier:
    """
    A classifier for distinguishing between images of zeros and ones using logistic regression.

    Attributes:
        ones_directory (str): Path to the directory containing images of ones.
        zeroes_directory (str): Path to the directory containing images of zeros.
        image_data (list): List to store pixel values of loaded images.
        image_labels (list): List to store labels corresponding to loaded images.
        classifier_model (LogisticRegression): The logistic regression model for classification.
    """
    
    def __init__(self, ones, zeroes):
        """
        Initializes the classifier with directories for images of ones and zeros.
        
        Args:
            ones (str): Path to the directory with images of ones.
            zeroes (str): Path to the directory with images of zeros.
        """
        self.ones_directory = ones
        self.zeroes_directory = zeroes
        self.image_data = []
        self.image_labels = []
        self.classifier_model = LogisticRegression(max_iter=1000)

    def load_and_process_images(self):
        """
        Loads images from specified directories, converts them to grayscale, resizes them, 
        and stores their pixel values along with their labels.
        """
        for directory, label in [(self.ones_directory, 1), (self.zeroes_directory, 0)]:
            for image_filename in os.listdir(directory):
                if image_filename.endswith(('.png', '.jpg')):
                    image_path = os.path.join(directory, image_filename)
                    image = Image.open(image_path).convert('L')  # Convert image to grayscale
                    image = image.resize((28, 28))  # Resize to 28x28 pixels
                    pixel_values = list(image.getdata())  # Get pixel values
                    self.image_data.append(pixel_values)
                    self.image_labels.append(label)  # Append label

    def train_and_evaluate_classifier(self):
        """
        Trains the logistic regression classifier on the processed image data and evaluates its performance.
        Outputs accuracy and classification report.
        """
        # Prepare data for training
        data_frame = pd.DataFrame(self.image_data)
        data_frame['label'] = self.image_labels
        X = data_frame.drop('label', axis=1)  # Features (pixel data)
        y = data_frame['label']  # Labels (0 or 1)

        # Split into training and testing datasets
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

        # Train the logistic regression model
        self.classifier_model.fit(X_train, y_train)

        # Predict on the test set
        y_pred = self.classifier_model.predict(X_test)

        # Evaluate the model's performance
        accuracy = accuracy_score(y_test, y_pred)
        report = classification_report(y_test, y_pred)

        # Output accuracy and classification metrics
        print(f"Accuracy: {accuracy}")
        print("Classification Report:")
        print(report)

    def save_model(self, model_path):
        """
        Saves the trained logistic regression model to a specified path using joblib.
        
        Args:
            model_path (str): The path where the model will be saved.
        """
        joblib.dump(self.classifier_model, model_path)
        print(f"Model saved to {model_path}")

# Directories for ones and zeroes images
ones = "D:/Testing/Ml/image_classification/Sample Images/One"
zeroes = "D:/Testing/Ml/image_classification/Sample Images/Zero"
model_path = 'logistic_model.pkl'

# Initialize the logistic regression classifier
digit_classifier = LogisticRegressionClassifier(ones, zeroes)

# Load and process images
digit_classifier.load_and_process_images()

# Train the model and evaluate its performance
digit_classifier.train_and_evaluate_classifier()

# Save the trained model
digit_classifier.save_model(model_path)
