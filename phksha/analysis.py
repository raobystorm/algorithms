import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression

class AnalysisDataAndFitLinearRegression:

    def __init__(self):
        self.version = 1

    def analyse_and_fit_lrm(self, path):
        data = pd.read_csv(path)
        data = self.__listwise_deletion(data)

        # calc statistics
        target = data.loc[data['Bedroom'].eq(4) & data['Bathroom'].eq(2)]
        statistics = [
            target['Tax'].mean(),
            target['Tax'].std(),
            target['Tax'].median(),
            target['Tax'].min(),
            target['Tax'].max(), 
        ]
        # calc data_frame
        data_frame = data.loc[data['Space'] > 800].sort_values(by=['Price'])

        # calc number_of_observations
        number_of_observations = data.loc[data['Lot'] > data.Lot.quantile(0.8)].shape[0]

        summary_dict = {
            'statistics': statistics,
            'data_frame': data_frame,
            'number_of_observations': number_of_observations
        }

        price_mean = data['Price'].mean() 
        price_std = data['Price'].std()
        data['Price'] = (data['Price'] - price_mean) 
        data['Price'] /= price_std

        space_mean = data['Space'].mean()
        space_std = data['Space'].std()
        data['Space'] = (data['Space'] - space_mean) 
        data['Space'] /= space_std

        lot_mean = data['Lot'].mean()
        lot_std = data['Lot'].std()
        data['Lot'] = (data['Lot'] - lot_mean) 
        data['Lot'] /= lot_std 

        tax_mean = data['Tax'].mean()
        tax_std = data['Tax'].std()
        data['Tax'] = (data['Tax'] - tax_mean) 
        data['Tax'] /= tax_std 

        x = data
        y = pd.DataFrame(x.iloc[:, 0])
        x = x.drop(['Price'], axis=1)
        y.Price = y.Price.astype(float)
        
        model = LinearRegression()
        model.fit(x, y)

        test = x.iloc[0:0]
        test = test.append({
            'Bedroom': 3.0,
            'Space': (1500 - space_mean) / space_std,
            'Room': 8,
            'Lot': (40 - lot_mean) / lot_std,
            'Tax': (1000 - tax_mean) / tax_std,
            'Bathroom': 2,
            'Garage': 1,
            'Condition': 0,
        }, ignore_index=True)

        price_prediction = float((model.predict(test) * price_std) + price_mean)

        return {
            'summary_dict': summary_dict,
            'regression_dict': {
                'model_parameters': model.get_params(),
                'price_prediction': price_prediction
            }
        }

    def __listwise_deletion(self, data: pd.DataFrame):
        return data.dropna()


lr = AnalysisDataAndFitLinearRegression()
print(lr.analyse_and_fit_lrm("./realest.csv"))