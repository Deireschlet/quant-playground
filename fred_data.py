import requests
import os
import pandas as pd
from datetime import datetime
from dotenv import load_dotenv

load_dotenv()


SERIES_ID = "FPCPITOTLZGUSA"
API_KEY = os.getenv("FRED_API_KEY")
FRED_URL = f"https://api.stlouisfed.org/fred/series/observations?series_id={SERIES_ID}&api_key={API_KEY}&file_type=json"
ALFRED_URL = f"https://api.stlouisfed.org/fred/series/observations?series_id={SERIES_ID}&realtime_start=1776-07-04&realtime_end=9999-12-31&api_key={API_KEY}&file_type=json"

def create_df(data: list) -> pd.DataFrame:
    df = pd.DataFrame(data)
    df = df[['date', 'value']]
    df['date'] = pd.to_datetime(df['date'])
    df['value'] = pd.to_numeric(df['value'])
    df = df.sort_values('date').reset_index(drop=True)

    return df

def save_csv(name: str, data: pd.DataFrame) -> None:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    filename = f"{name}_{timestamp}.csv"
    data.to_csv(filename, index=False)
    return None

def main():
    fred_response = requests.get(FRED_URL)
    alfred_response = requests.get(ALFRED_URL)
    fred_data = fred_response.json()
    alfred_data = alfred_response.json()
    
    fred_observations = fred_data['observations']
    alfred_observations = alfred_data['observations']

    fred_df = create_df(fred_observations)
    alfred_df = create_df(alfred_observations)
    
    save_csv("./data/FRED_" + SERIES_ID, fred_df)
    save_csv("./data/ALFRED_" + SERIES_ID, alfred_df)

if __name__ == "__main__":
    main()
